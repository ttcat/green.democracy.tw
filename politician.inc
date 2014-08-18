<?php
require_once 'api/api.inc';

//timeline
$string = file_get_contents("http://v.democracy.tw/test/news.json");
$newsfeeds = json_decode($string,true);
$newsfeeds = $newsfeeds['nodes'];

?><!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
    <head>
        <meta charset="utf-8">
        <!--[if IE]><meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"><![endif]-->
        <meta content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no" name="viewport">
        <meta content="black" name="apple-mobile-web-app-status-bar-style">
        
        <title><?=$user['title']?> | 2014 綠黨政治代理人</title>
        <meta name="description" content="Enter Description">

         <link rel="stylesheet" type="text/css" href="/css/normalize.min.css">
         <link rel="stylesheet" type="text/css" href="/css/main.css?<?=time()?>">
         <link rel="stylesheet" type="text/css" href="/timeline/files/css/timeline_themegp.css?<?=time()?>" />

         <!-- Remove responsive.css is non-responsive needed -->
         <link rel="stylesheet" type="text/css" href="/css/responsive.css?<?=time()?>">
         <link rel="stylesheet" type="text/css" href="/css/flexslider.css">
         <link rel="stylesheet" type="text/css" href="/css/font-awesome.css">
         <link rel="stylesheet" type="text/css" href="/js/fancybox/jquery.fancybox.css?v=2.1.4" media="screen" />
         <link rel="stylesheet" type="text/css" href="/rs-plugin/css/settings.css" media="screen" />         
         <script src="/js/vendor/modernizr-2.6.2-respond-1.1.0.min.js"></script>         
         
    </head>
    <body>
    	
	<? require_once 'api/header.inc'; ?>
    	
    	
    <div class="outter-wrapper">	
    	 <!-- Start Main Body -->
        <div class="main-container">
            <div class="main wrapper clearfix">
            	<!-- Start Main Content -->				
            	
                <div class="main-content three-fourths">
				

				<!-- add here-->

        <div id="timeline" style="margin-top:20px; margin-bottom:20px;" class="timeline"></div>
		<div class="timeline_loadmore" id="loadmore" style="display:none;">
    		<em class="icon-refresh"></em> 顯示更多
    	</div>

				<!-- add here-->


                </div>
				
				<!-- Start Main Sidebar  -->
					<? require_once 'api/sidebar.inc'; ?>
				<!-- Finish Sidebar -->

        	</div> <!-- #main -->
        </div> <!-- #main-container -->
    </div>	


					<? require_once 'api/footer.inc'; ?>


		
	<!-- /////////////////// --> 
	<!-- Start Scripts -->
		<!--<script type="text/javascript" src="js/vendor/jquery-1.8.3.min.js"></script>-->
	<script src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>
		        				
	<script type="text/javascript" src="/js/fitvids.min.js"></script>
	<script type="text/javascript" src="/js/fancybox/jquery.fancybox.js?v=2.1.4"></script>
	<script type="text/javascript" src="/js/placeholder.js"></script>
	<script type="text/javascript" src="/js/jquery.flexslider-min.js"></script>
	<script type="text/javascript" src="/js/mosaic.1.0.1.min.js"></script>
	<script type="text/javascript" src="/js/cleantabs.jquery.js"></script>

	<script type="text/javascript" src="/rs-plugin/js/jquery.themepunch.plugins.min.js"></script>
	<script type="text/javascript" src="/rs-plugin/js/jquery.themepunch.revolution.min.js"></script>
	<script type="text/javascript" src="/js/rs-slider.js"></script>

	<script type="text/javascript" src="/js/contact.js"></script>
	<script type="text/javascript" src="/js/jquery.form.js"></script>
	<script type="text/javascript" src="/js/jquery.validate.min.js"></script>
	<script type="text/javascript" src="/js/twphone.js"></script>

	<script type="text/javascript" src="/js/jquery.stellar.min.js"></script>
	<script type="text/javascript" src="/js/jquery.scrollUp.min.js"></script>
	<script type="text/javascript" src="/js/selectivizr-min.js"></script>
	
	<script src="/js/kkcountdown.min.js" type="text/javascript"></script>
	<script type="text/javascript">
            $(document).ready(function(){
                $(".kkcount-down").kkcountdown({
                	dayText		: '',
                	daysText 	: '',
                    hoursText	: ':',
                    minutesText	: ':',
                    secondsText	: '',
                    displayZeroDays : false,
                    oneDayClass	: 'oneday'
                });
            });
        </script>

	<script type="text/javascript" src="/js/fittext.js"></script>	
    <script type="text/javascript">
		// FitText.js
		fitText(document.getElementById('promise'), 0.83)
	</script>
	<script type="text/javascript" src="/js/main.js?<?=time?>"></script>

    <script type="text/javascript" src="/timeline/files/javascript/timeline.js"></script>			

        <script type="text/javascript">
            $(document).ready(function() {
            
                var init_data = [

	<?  
	
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
				$str_media = "['" . impolde("','", $media) . "']";					
			}

			if($feed['category'] == 'slider') { 
				$media = explode("|", $feed['photo']);	
				$str_media = "['" . impolde("','", $media) . "']";					
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
				        <? if($feed['photo']) { ?>image: '<?=$str_media?>', <? } ?> // 照片
				        
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
                    
                ];

				var total_feeds = <?=count($newsfeeds)?>; 
				var feeds_left = total_feeds - init_data.length;

							if(feeds_left <= 0) {
				                $('#loadmore').css('display', 'none');
							}else{
				                $('#loadmore').css('display', 'block');
							}							
				
				var rwd_js = $(window).width();
				if(rwd_js < 770) { columnMode_t = 'right';} else { columnMode_t = 'dual'; }

                var timeline = new Timeline($('#timeline'), init_data);
                timeline.setOptions({
                	responsive_width : 770,
                    animation:       true,
                    lightbox:        true,
                    first_separator: false,
                    separator:       'null',
                    columnMode:  columnMode_t,
                    order:           'desc',
                    loadmore: feeds_left,
                });
                timeline.display();



                // load more click
                var year = 2011;   
                $('#loadmore').on('click', function(e) {
                    var button = $(this);
                    if (button.hasClass('notice')) {
                        return;
                    }
                    year--;
                    button.addClass('notice').text('讀取中...');

                    $.ajax('ajax_data.php', {
                        type     : 'POST',
                        dataType : 'json',
                        data     : {year: year},
                        success  : function(data) {
                            // remove loading
							button.css('display', 'none');                            
                            button.removeClass('notice').html('<em class="icon-refresh"></em> 顯示更多');
                            // append new data
                            timeline.appendData(data);
							feeds_left = feeds_left - data.length;

							if(feeds_left <= 0) {
								button.css('display', 'none');
							}else{
								button.css('display', 'block');
							}							
		
                        }
                    });
                });
            });
            
            

            
        </script>
 
	</body>
</html>
