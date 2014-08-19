<?php
require_once 'api/api.inc';

//分頁

//newsfeeds
$string = file_get_contents("http://v.democracy.tw/{$u}/news.json");
$newsfeeds = json_decode($string,true);
$newsfeeds = $newsfeeds['nodes'];

//政見

$string = file_get_contents('http://v.democracy.tw/test/event.json');
$events = json_decode($string, true);
$events = $events['nodes'];

//活動

$string = file_get_contents('http://v.democracy.tw/test/issue.json');
$issues = json_decode($string, true);
$issues = $issues['nodes'];

//相簿

$string = file_get_contents('http://v.democracy.tw/test/galleries.json');
$gallery = json_decode($string, true);
$gallery = $gallery['nodes'];

foreach($gallery as $key => $v) {
	$gallery[$key]['node']['date'] = date("Y-m-d" ,strtotime($v['node']['post date']));
}
	

//推薦
//$endorsment already get from api.icnc


//combian_all arrays
$all_feeds = array_merge($newsfeeds, $events, $issues, $gallery, $endorsment);


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
			    "newsfeed" => array("blog_post", "選舉動態",200),
			    "slider" => array("slider", "選舉動態", 200),
			    "video" => array("iframe", "選舉動態", 300),
		    	"newsclip" => array("news", "相關新聞",200),

		    	"FAQ" => array("blog_post", "政見", 200),
		    	"Person" => array("blog_post", "各界推薦", 200),
		    	"Event" => array("blog_post", "活動行程", 200),
		    	"gallery" => array("blog_post", "相簿", 300),
			);

		foreach ($rows as $k => $feed) { 

			$feed = $feed['node'];
			
			if($feed['type'] == "News") { 
			
				if( ! $feed['category']) $feed['category'] = 'newsfeed';

				if($feed['category'] == 'slider') { 
					$media = explode("|", $feed['photo']);	
				}
				$json_this_feed['type'] = $cats[ $feed['category'] ][0];
				$json_this_feed['title'] = $cats[$feed['category']][1];
				$json_this_feed['height'] = $cats[$feed['category']][2];				
			}else{
				$json_this_feed['type'] = $cats[ $feed['type'] ][0];
				$json_this_feed['title'] = $cats[$feed['type']][1];
				$json_this_feed['height'] = $cats[$feed['type']][2];
			}

			if($feed['media']) { 
				$media = explode("|", $feed['media']);	
			}

			if($feed['category'] == 'slider' || $feed['category'] == 'slider') { 
		        $json_this_feed['images'] = $media;
			}else{
				if($feed['photo']) { 
			       $json_this_feed['image'] = $feed['photo'];
				}
			}
			
			$json_this_feed['date'] = date('Y-m-d' ,strtotime($feed['date']));
			$json_this_feed['dateFormat'] = 'YYYY-MM-DD';
			$json_this_feed['speed'] = 5000;

			if($feed['sticky'] != "No") { $json_this_feed['star'] = true;	//置頂

			if($feed['link']) {					
				$parse_result = '';
				$parse_result = parse_url($feed['link']);
				if($parse_result['host'] != $_SERVER['HTTP_HOST'] ) { $target = 'target="blank"'; } else { $target = ''; }
				//<span class="icon-"></span>
				$feed['title'] = '<a href="'.$feed['link'].'" '.$target.'>' . $feed['title'] . '</a>';
				$json_this_feed['readmore'] = $feed['link'];
			}

			if($feed['category'] == 'video') { 
				$json_this_feed['url'] = $feed['videolink'];
			}

			$feed['content'] = SL(str_replace("\n","",$feed['content']),250);

			$event_time = '';
			//event 加上按鈕
			if($feed['type'] == 'Event') { 
				$feed['content'] .= '<a href="'. $feed['link'] .'" class="btn small-btn"><em class="icon-chevron-sign-right"></em>我要參加！</a>'; 
				$event_time = '<h6>' . $feed['eventtime']  . ' / ' . $feed['location'] .'</h6>';
				}

            $json_this_feed['content'] = '<h3>' . $feed['title'] . '</h3><p>' . $event_time . $feed['content']  . '</p>';
            if($target) { $json_this_feed['target'] = 'target="blank"'; }else{ $json_this_feed['target'] = ''; } 


			$json[] = $json_this_feed;

		} //end foreach	

	
	print_r(json_encode($json, true));



<? /*                    
                                                            
                    {
                        type:     'gallery',
                        date:     '2011-04-12',
                        title:    '相簿',
                        height:   250,
                        images:   ['images/rooney.jpg', 'images/tshirt.jpg', 'images/giggs.jpg', 'images/rio.jpg', 'images/paper.jpg'],
                        content:  '<h3><a href="#"><span class="icon-"></span> 新聞標題新聞標題新聞標題新聞標題</a></h3><p>新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文新聞短文</p>',
				        readmore:    'http://www.example.com'                        
                        
                    },
                                                    
                    {
                        type:     'blog_post',
                        date:     '2013-11-09',
                        dateFormat:  'YYYY-MM-DD',                        
                        title:    '活動行程',
                        content:  '<h3><a href="#"><span class="icon-calendar-empty"></span> 活動：募款晚會</a></h3><h6>2014.09.10 / 高雄市</h6><p>Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla varius blandit sit, Aenean lacinia bibendum nulla sed consectetur. Maecenas sed diam eget risus lorem ipsum dolor sit amet, consectetur adipiscing elit&#8230;</p><a href="#" class="btn small-btn"><em class="icon-chevron-sign-right"></em>我要參加！</a>',
				        readmore:    'http://www.example.com'
                    },


                    {
                        type:     'blog_post',
                        date:     '2013-11-09',
                        dateFormat:  'YYYY-MM-DD',                        
                        title:    '政見',
                        content:  '<h3><a href="#"><span class="icon-globe"></span> 政見短文政見短文政見短文政見短文政見短文</a></h3><p>政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見政見</p>',
				        readmore:    'http://www.example.com'
				                                
                    },

*/ 


function aasort ($array, $key) {
    $sorter=array();
    $ret=array();

    foreach ($array as $ii => $va) {
        $sorter[$va['node']['sort_id']] = $va['node'][$key]; //depends on format of array
    }

    arsort($sorter); //DESC by vaule with key
    	
    foreach ($sorter as $ii => $va) {
    	if($va) {
    		foreach ($array as $k => $value) {
    			if($value['node']['sort_id'] == $ii) {
			        $ret[]=$value;
    			}
    		}	        
	    }
    }
        
    $array=$ret;    
    return $array;
}
?>