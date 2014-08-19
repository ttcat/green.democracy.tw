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

//推薦
//$endorsment


//combian_arrays

$all_feeds = array_merge($newsfeeds, $events, $issues, $gallery, $endorsment);

print_r(json_encode($all_feeds, true));


exit;



//處理 json;
	
			$cats = array(
			    "newsfeed" => array("blog_post", "選舉動態",200),
			    "slider" => array("slider", "選舉動態", 200),
			    "video" => array("iframe", "選舉動態", 300),
		    	"newsclip" => array("news", "相關新聞",200),
			);

		foreach ($newsfeeds as $k => $feed) { 

			$feed = $feed['node'];
			if(!$feed['category']) $feed['category'] = 'newsfeed';

			if($feed['media']) { 
				$media = explode("|", $feed['media']);	
				$str_media = "[\"" . implode("\",\"", $media) . "\"]";
			}

			if($feed['category'] == 'slider') { 
				$media = explode("|", $feed['photo']);	
				$str_media = "[\"" . implode("\",\"", $media) . "\"]";
			}else{
				$str_media = $feed['photo'];
			}
			
			
			
			
			if($feed['link']) {
					
					$parse_result = '';
					$parse_result = parse_url($feed['link']);
					if($parse_result['host'] != $_SERVER['HTTP_HOST'] ) { $target = 'target="blank"'; } else { $target = ''; }
					//<span class="icon-"></span>
					$feed['title'] = '<a href="'.$feed['link'].'" '.$target.'>' . $feed['title'] . '</a>';
				}


			?>
                    {
                        type:    '<?=$cats[$feed['category']][0]?>',
                        date:     '<?=date('Y-m-d' ,strtotime($feed['date']))?>',
                        dateFormat:  'YYYY-MM-DD',
                        title:    '<?=$cats[$feed['category']][1]?>',
                        
				        <? if($feed['sticky'] != "No") { ?>star: true,<? } ?>	//置頂

				        <? if($feed['category'] == 'slider') { 
					        if($feed['photo']) { ?>images: <?=$str_media?>, <? } ?> // 照片
					    <? } else{ ?>
					        <? if($feed['photo']) { ?>image: '<?=$str_media?>', <? } ?> // 照片				        				        
					    <? } ?>
					    
                        height:   <?=$cats[$feed['category']][2]?>,	//slider 200, gallery 300, video/iframe 300
                        speed:    5000,

						<? if($feed['category'] == 'video') { ?>url: '<?=$feed['videolink']?>',<? } ?>
                        content:  '<h3><?=$feed['title']?></h3><p><?=SL(str_replace("\n","",$feed['content']),250)?></p>',
                        <? if($feed['link']) { ?>readmore:    '<?=$feed['link']?>', <? } ?>
                        <? if($target) { ?>target: 'target="blank"'<? }else{ ?>target: '', <? } ?>
                        
                    },
			<? } ?>                    
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
				        image:       'img/thumb-1.jpg',
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

*/ ?>