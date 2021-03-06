<?php
function get_timeline($print = TRUE){
global $u, $page, $nid;

  $perpage = 8;
  if($page == 0) $page = 1;
  
  $start_feed = ( ((int) $page)  - 1 ) * $perpage;
  $end_feed = $start_feed + $perpage - 1;

  if($page == 'all') { $end_feed = 0;  }
  if($nid) { $end_feed = 0;  }

  $string = http_request_contents("http://v.democracy.tw/{$u}/timeline.json", 60*5);
  $all_feeds = json_decode($string,true);
  $all_feeds = $all_feeds['nodes'];

  //sorting
  $i = 0;
  foreach($all_feeds as $key => $v) {
    $v['node']['sort_id'] = 'sort-'.$i;
    $all_feeds_new[] = $v;
    $i ++;
  }

  $rows = aasort($all_feeds_new,"date");
  //print_r(json_encode($all_feeds_new, true));
  //print_r(json_encode($rows, true));

  //處理 json;
    
        $cats = array(
            "newsfeed" => array("blog_post", "選舉動態",200, 'politician/'),
            "slider" => array("gallery", "動態相簿", 'auto', 'politician/'),
            "video" => array("iframe", "選舉動態", 'auto', 'politician/'),
            "newsclip" => array("news", "相關新聞",200, 'politician/'),

            "FAQ" => array("blog_post", "政見", 200, 'issues/'),
            "Person" => array("blog_post", "各界推薦", 200, 'endorsements/'),
            "Event" => array("blog_post", "活動行程", 200, 'event/'),
            "gallery" => array("gallery", "相簿", 300, ''),
        );


      $jj = 0;
      $json = array();
      $json_this_feed = array();
      
      foreach ($rows as $k => $feed) { 

        $json_this_feed = array();
        $linkpage_array = array();
        $target_text = null;
              
        $feed = $feed['node'];

        if($feed['sticky'] == "Yes") { $json_this_feed['star'] = 1; } else { 	$json_this_feed['star'] = 0; }//置頂
        
        if($feed['type'] == "") { $feed['type'] = 'gallery'; }  //測試

        if($feed['type'] == "News") { 
          if( ! $feed['category']) $feed['category'] = 'newsfeed';

          if($feed['category'] == 'slider') { 
            $media = $feed['photo'];
	        $json_this_feed['images'] = $media;
            
          }

          $json_this_feed['type'] = $cats[ $feed['category'] ][0];
          $json_this_feed['title'] = $cats[$feed['category']][1];
          $json_this_feed['height'] = $cats[$feed['category']][2];
          $linkpage = $cats[$feed['category']][3];	
          
        }else{
          $json_this_feed['type'] = $cats[ $feed['type'] ][0];
          $json_this_feed['title'] = $cats[$feed['type']][1];
          $json_this_feed['height'] = $cats[$feed['type']][2];
          $linkpage = $cats[$feed['type']][3];	
        }


	if($feed['professional_title']) { 
		$json_this_feed['professional_title']; 
	}


	if($feed['caption']) { 
		$json_this_feed['caption']; 
	}


	if($feed['content-title']) { 
		$json_this_feed['content-title']; 
	}


	if($feed['short-content']) { 
		$json_this_feed['short-content']; 
	}


	if($feed['icon']) { 
		$json_this_feed['icon']; 
	}

	if($feed['tag']) { 
		$json_this_feed['tag']; 
	}
	
	
        if($feed['videolink']) {
          $json_this_feed['videolink'] = metavideo($feed['videolink'], 0);
          $feed['link'] = $feed['videolink'];
        }

        if($feed['type'] != 'Event') { 
	        if(! $feed['link'] && $linkpage) { 
    	      $feed['link'] = 'http://green.democracy.tw/' . $u . '/' .$linkpage. '' . $feed['nid'];
	        }
	    }
      
      if($json_this_feed['type']) { 
      
        if($feed['media']) { 
          $media = explode("|", $feed['media']);	
          $json_this_feed['images'] = $media;
        }
          
        if($feed['photo']) { 
            $json_this_feed['image'] = $feed['photo'];
        }
        
        if($feed['videolink']) {
          $json_this_feed['videolink'] = metavideo($feed['videolink'], 0);
        }
              
        $json_this_feed['date'] = date('Y-m-d' , strtotime($feed['date']));
        $json_this_feed['dateFormat'] = 'YYYY-MM-DD';
        $json_this_feed['speed'] = 5000;
        $json_this_feed['nid'] = $feed['nid'];


        if($feed['type'] == 'Person') {
          $feed['title'] = $feed['title'] . ' / ' . $feed['professional_title'] ;
        }

        //<span class="icon-cc"></span> 標題前面加上 icon
        
        if($feed['icon']) { $feed['title'] = '<em class="fa '.$feed['icon'].'"></em>'. $feed['title'];  } 
		if($feed['type'] == 'Person') {		$feed['title'] = '<em class="fa fa-thumbs-up"></em>'. $feed['title']; }
		

        if($feed['link']) {	
          $parse_result = '';
          $parse_result = parse_url($feed['link']);
          
          if($parse_result['host'] != $_SERVER['HTTP_HOST'] ) { $target = 'blank'; } else { $target = ''; }
          if($target) { $json_this_feed['target'] = 'blank'; }else{ $json_this_feed['target'] = ''; } 
          if($json_this_feed['target'] == 'blank') { $target_text = 'target="_blank"'; }

          $feed['title'] = '<a href="'.$feed['link'].'" '.$target_text.'>' . $feed['title'] . '</a>';
          $json_this_feed['readmore'] = $feed['link'];
        }
              
        if($feed['category'] == 'video') { 
          $json_this_feed['videolink'] = metavideo($feed['videolink'], 0);
        }			
        
        $org_content = $feed['content'];

        $allowed_tags = array('a', 'em', 'strong', 'cite', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd','p','br');
		$feed['content'] = filter_xss($feed['content'], $allowed_tags);
		
        if(!$nid) { 
        	$feed['content'] = SL(str_replace("\n","",$feed['content']), 200); 
        }

        $event_time = '';
        //event 加上按鈕
        if($feed['type'] == 'Event') { 

		if (strpos($feed['eventtime'],'</div>') !== false) {
			$eventtime = explode('</div>', $feed['eventtime']);
			$feed['eventtime'] = $eventtime[1];
		}
		
		
			$feed['title'] = '<em class="fa fa-calendar"></em>'. $feed['title'];
            $event_timestamp_str = explode(' to ',strip_tags($feed['eventtime']));
            $event_timestamp_date = explode(' ',strip_tags($feed['eventtime']));
			
   
      		$event_timestamp = strtotime($event_timestamp_date[0].' '.$event_timestamp_str[1]);

   			if(strpos($event_timestamp_str[1], '2014') !== false) {			
				$event_timestamp = strtotime($event_timestamp_str[1]);
   			}
			            
            $json_this_feed['timestamp'] = $event_timestamp;
            $json_this_feed['timestamp_str'] = time();
            
            if(!$feed['link'] || strpos($feed['link'], 'http') == false) { 
            
            	$feed['link'] = "#";
            
            }else{
            
	            if(time() > $event_timestamp) { 
    	          $button_text = '<a href="'. $feed['link'] .'" ' . $target_text . ' class="btn small-btn btn-style2"><em class="fa fa-thumbs-up"></em>活動結束</a>';
        	     }else{ 
            	  $button_text ='<a href="'. $feed['link'] .'" ' . $target_text . ' class="btn small-btn"><em class="fa fa-thumbs-up"></em>我要參加！</a>';
	            }
    		}        
            
            
            $feed['content'] = '<p>' . $feed['content'] . '</p><p></p>'.$button_text.'<br>'; 
            $event_time = '<h6>' . $feed['eventtime']  . ' <br> ' . $feed['location'] .'</h6>';
          }


              $json_this_feed['content'] = '<h3>' . $feed['title'] . '</h3><p>' . $event_time . $feed['content'];
          if($feed['type'] != 'Event') {  $json_this_feed['content'] .=   '<div id="timeline_fb_' . $feed['nid'] .'" class="addthis_sharing_toolbox addthis_default_style addthis_20x20_style" data-url="http://green.democracy.tw/' . $u . '/' .$linkpage. $feed['nid'] . '">'; }

          if($feed['type'] != 'Event') {  
              if($page != 'all' && $page > 1)
              { 
                $json_this_feed['content'] .=  '<a class="addthis_button_facebook" style="padding: 0px;" addthis:url="http://green.democracy.tw/' . $u . '/' .$linkpage. $feed['nid'] . '" ></a><a style="padding: 0px;" class="addthis_button_twitter" addthis:url="http://green.democracy.tw/' . $u . '/' .$linkpage. $feed['nid'] . '" ></a><a style="padding: 0px;" class="addthis_button_google_plusone_share" addthis:url="http://green.democracy.tw/' . $u . '/' .$linkpage. $feed['nid'] . '" ></a><a style="padding: 0px;" class="addthis_button_compact" addthis:url="http://green.democracy.tw/' . $u . '/' .$linkpage. $feed['nid'] . '" ></a>';
	            }
              $json_this_feed['content'] .= '</div></p>';
        	}

        if($linkpage) $linkpage_array = explode('/', $linkpage);
        $json_this_feed['section'] = $linkpage_array[0];

          if($end_feed == 0) // show_all
          {
            $json[] = (array) $json_this_feed;
            
          }else if($jj >= $start_feed && $jj <= $end_feed) //分頁控制在此
          {
            $json[] = (array) $json_this_feed;
          }
          
          
        $jj ++;
        
        }
      } //end foreach	

    $json[0]['perpage'] = $perpage;
    $json[0]['total'] = $jj;
    $json[0]['thispage'] = $start_feed;

      
  $json_str = json_encode($json);
  if(!$print){
    return $json_str;
  }
  else{
    print $json_str;
  }
}

function aasort ($array, $key) {

    $sorter=array();
    $ret=array();

    foreach ($array as $ii => $va) {

      if($va['node']['sticky'] = "Yes" ) { 
          $sorter[$va['node']['sort_id']] = '9' . $va['node'][$key]; //depends on format of array
        }else{
          $sorter[$va['node']['sort_id']] = $va['node'][$key]; //depends on format of array        
        }
        
    }

    arsort($sorter); //DESC by value with key
      
    foreach ($sorter as $ii => $va) {
      if($va) {
        foreach ($array as $k => $value) {
          if($value['node']['sort_id'] == $ii) {
              $ret[] = $value;
          }
        }	        
      }
    }
        
    $array=$ret;    
    return $array;
}
