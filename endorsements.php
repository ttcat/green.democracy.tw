<?php
require_once 'api/api.php';

//timeline
$string = file_get_contents("http://v.democracy.tw/test/news.json");
$newsfeeds = json_decode($string,true);
$newsfeeds = $newsfeeds['nodes'];

//個人資料
$string = file_get_contents("http://v.democracy.tw/test/site.json");
$user = json_decode($string,true);
$user = $user['nodes'][0]['node'];

//推薦
$string = file_get_contents("http://v.democracy.tw/test/people.json");
$recommendation = json_decode($string,true);
$recommendation = $recommendation['nodes'];

shuffle($recommendation);


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

         <link rel="stylesheet" type="text/css" href="css/normalize.min.css">
         <link rel="stylesheet" type="text/css" href="css/main.css?<?=time()?>">
         <link rel="stylesheet" type="text/css" href="timeline/files/css/timeline_themegp.css?<?=time()?>" />

         <!-- Remove responsive.css is non-responsive needed -->
         <link rel="stylesheet" type="text/css" href="css/responsive.css?<?=time()?>">
         <link rel="stylesheet" type="text/css" href="css/flexslider.css">
         <link rel="stylesheet" type="text/css" href="css/font-awesome.css">
         <link rel="stylesheet" type="text/css" href="js/fancybox/jquery.fancybox.css?v=2.1.4" media="screen" />
         <link rel="stylesheet" type="text/css" href="rs-plugin/css/settings.css" media="screen" />         
         <script src="js/vendor/modernizr-2.6.2-respond-1.1.0.min.js"></script>         
         
    </head>
    <body>
    	
	<? require_once 'api/header.php'; ?>
    	
    	
    <div class="outter-wrapper">	
    	 <!-- Start Main Body -->
        <div class="main-container">
            <div class="main wrapper clearfix">
            	<!-- Start Main Content -->				
            	
                <div class="main-content three-fourths">
				

				<!-- add here-->
				<h2>各界推薦</h2>
						<hr>
						
						<p>
						<blockquote>
						<strong>公民參政共同監督意願書</strong></br></br>
						
						<div class="half">
	                       	<img src="img/thumb-1.jpg" alt="mock" width="100%" height="140px">
	                       	<span class="wp-caption-text">擔任主婦聯盟合作社生態解說員</span>
	                    </div>
	                    被監督人 張明麗君 對於食安議題關注甚深、熱心公益，在基隆七堵地區推動共同購買，為本社基隆市七堵區綠葉山莊共同購買班創班班長，同時為本社解說員、基隆地區社員代表；平日在組織活動中，對於綠色生活之觀念皆能實踐、身體力行。<br/></br>
						該君為實踐公民參政理想，並將食農議題、永續環境理念廣佈於基隆地區，決定代表綠黨投入2014年基隆市市議員選舉，作為一個長期關注台灣食農議題的社運團體，我們樂觀其成，並願意扮演監督者的角色，與社會各界共同監督，真正落實公民參政的理念。<br/></br>此致<br/></br>
						<cite>- 台灣主婦聯盟生活消費合作社</cite>
    	                </blockquote>
    	                </p>
	
						<hr>	

						<p>
						<blockquote>" Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Cras justo odio, acilisis in, egeet quam. " <cite>- James Dean</cite>
    	                </blockquote>
    	                </p>
	
						<hr>	

						<p>
						<blockquote>" Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Cras justo odio, acilisis in, egeet quam. " <cite>- James Dean</cite>
    	                </blockquote>
    	                </p>
	
						<hr>	

						<p>
						<blockquote>" Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Cras justo odio, acilisis in, egeet quam. " <cite>- James Dean</cite>
    	                </blockquote>
    	                </p>
	
						<hr>	

						<p>
						<blockquote>" Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Cras justo odio, acilisis in, egeet quam. " <cite>- James Dean</cite>
    	                </blockquote>
    	                </p>
	
						<hr>	

						<p>
						<blockquote>" Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante venenatis dapibus posuere velit aliquet. Cras justo odio, acilisis in, egeet quam. " <cite>- James Dean</cite>
    	                </blockquote>
    	                </p>
    	                
    	                    	                    	                    	                    	                
				<!-- add here-->
				</div>
				
				
				
				<!-- Start Main Sidebar  -->
				<aside class="right-aside fourth last">
			    	
			    	<? if($user['issues']) { ?>
				    	<div class="clearfix aside-focus">
                			<h3><strong>政見主要關注</strong></h3>
                			<ul class="statistics">
                				<li><em class="icon-globe"></em> <span>全球化貿易</span></li>
                				<li><em class="icon-flag"></em> <span style="color:black;">性/別與同志</span></li>
                				<li><em class="icon-legal"></em> <span style="color:black;">法律與人權</span></li>
                			</ul>	
                			<p><a class="more">了解目前的政見</a></p>
                		</div>
				    <? } ?>
				    
				    	                		
			    	<? if($user['recommendation']) { ?>                		
                		<!-- Quote Widget -->
				    	<div class="clearfix aside-recom">
                			<h3><strong>各界推薦</strong></h3>
                			<blockquote><?=$recommendation[0]['node']['contents']?><cite>- <?=$recommendation[0]['node']['title']?></cite></blockquote>
                		</div>
					<? } ?>	
					
			    	<? if($user['fundraising']) { ?>                		
				    	<div class="clearfix aside-donate">
                			<h3><strong>募款</strong></h3>
                			<p>捐款的短話捐款的短話捐款的短話捐款的短話捐款的短話捐款的短話</p>

                			<ol class="graphs">
                				<li><div class="per-60 btn-style2"> 1,203,234<span>60%</span></div></li>                				
                			</ol>
                			                			
                			<a href="#" class="btn small-btn "><em class="icon-heart"></em>線上捐款</a><p></p>
                		</div>	

                	<hr>
					<? } ?>

			    	<? if($user['gotv']) { ?>                		

                		<!-- Email Signup Widget -->
				    	<div class="clearfix aside-signup">
                			<h3 id="promise"><strong>承諾 <span time="1417219200" class="petition_count kkcount-down"></span> 天後投票</strong></h3>
                			<p>登記為本選區的選民、訂閱且隨時關注<?=$user['title']?>最新消息，並承諾在 <span class="highlight">11/29</span> 一定去投票！</p>
                			<form id="contactform" class="quick-contact" action="php/processForm.php" method="post">                			
                				<table class="tableless">
                					<tr><td><input type="text" id="name" name="name" placeholder="姓名" /></td></tr>
                					<tr><td><input type="email"id="email" name="email" placeholder="Email" value="" /></td></tr>
                					<tr><td><input type="text" id="phone" name="phone" placeholder="手機號碼" value="" maxlength="10" /></td></tr>                					
                					<tr><td><input type="text" id="message" name="message" placeholder="選區，例如%高雄市三民區%"></td></tr>
                					<tr><td>
									<input name="button" class="btn small-btn" type="submit" value="送出" id="send" /><br/></td></tr>
                				</table>
                			</form>
                			<div id="response"></div>
                		</div>
                					    	
			    	<hr/>
					<? } ?>

			    	<? if($user['news']) { ?>                		

                		<!-- Start Text Widget -->     
				    	<div class="clearfix aside-news">
                			<h3><strong>相關新聞</strong></h3>
                			<div class="mosaic-block fade">
                				<a href="#" class="mosaic-overlay link" title="新聞標題"></a><div class="mosaic-backdrop">
                				<div class="corner-date">8/26</div><img src="img/small_thumb3.jpg" alt="Mock" /></div>
                			</div>
                			<h3 class="title"><a href="#">新聞標題</a></h3>
                			<p>媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息
                			&#8230;<a class="more">更多</a></p>
                		</div>
                		
                <hr class="aside-news">
                <? } ?>
                
                
				<? if($user['gallery']) { ?>                		                		
			    	<!-- Start Gallery Widget -->
			    	
			    	<div class="clearfix gallery aside-gallery">

                	<h3><strong>Gallery</strong></h3>

			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half fade">
			    			<a href="img/thumb-1.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="img/thumb-1.jpg" alt="Start" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->	
			    		<div class="mosaic-block half last fade">
			    			<a href="img/thumb-2.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="img/thumb-2.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half fade">
			    			<a href="img/thumb-3.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="img/thumb-3.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half last fade">
			    			<a href="img/thumb-4.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="img/thumb-4.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half fade">
			    			<a href="img/thumb-5.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="img/thumb-5.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->	
			    		<div class="mosaic-block half last fade">
			    			<a href="img/thumb-6.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="img/thumb-6.jpg" alt="Mock" /></div>
			    		</div>
			    			
			    			
						<p><a class="more">更多</a></p>
	
			    	</div>

                <hr class="aside-gallery">                		
				<? } ?>
				
				
			    	
				    	<div class="clearfix aside-contact">
				    	
                			<h3><strong>聯繫<?=$user['title']?></strong></h3>
							<? if($user['fb']) { ?><div class="fb-like-box" style="margin-left: -10px; margin-bottom: 5px; margin-top: -5px;" data-href="<?=$user['fb']?>" data-width="200" data-colorscheme="light" data-show-faces="false" data-header="false" data-stream="false" data-show-border="false"></div><? } ?>
							<ul class="link-list">
    	       					<? if($user['website']) { ?><li><a href="#">網站名稱</a></li><? } ?>
    	       					<? if($user['phone']) { ?><li><a href="tel:<?=$user['phone']?>"><?=$user['phone']?></a></li><? } ?>
    	       					<? if($user['address']) { ?><li><a href="https://www.google.com.tw/maps/search/<?=$user['address']?>/?hl=zh-TW" target="blank"><?=$user['address']?></a></li><? } ?>
    	       					
    	       					<? if($user['email']) { ?><li><a href="emailto:<?=$user['email']?>"><?=$user['email']?></a></li><? } ?>
    	       				</ul>
                		</div>
			    	
			    	
			    		<a href="#" target="_blank">回到選舉動態首頁</a>

			    			    	
				</aside> 
				<!-- Finish Sidebar -->

        	</div> <!-- #main -->
        </div> <!-- #main-container -->
    </div>	


	<!-- /////////////////// --> 			
	<!-- Start Widget Footer -->
	<div class="outter-wrapper widget-footer main clearfix">
		<div class="wrapper clearfix">
			
			<!-- Start Column -->
			<div class="fourth widget">
				<h3>台灣綠黨</h3>
				<p>台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介台灣綠黨簡介</p>				
			</div>

			<!-- Start Column -->
			<div class="fourth widget footer-news">
				<h3>最新訊息</h3>
                			<div class="mosaic-block fade">
                				<a href="#" class="mosaic-overlay link" title="新聞標題"></a><div class="mosaic-backdrop">
                				<div class="corner-date">8/26</div><img src="img/small_thumb3.jpg" alt="Mock" /></div>
                			</div>
                			<h3 class="title"><a href="#">新聞標題</a></h3>
			</div> 

			
			<!-- Start Column -->	
			<div class="fourth widget footer-signup">
				<h3>訂閱電子報</h3>
				<p>關注綠黨最新消息</p>
            <form id="subscribe-newsletter" style="margin-top:0;" action="#" method="post">                							
				<input type="email" placeholder="Email" name="email" id="email" value="" />
				<input type="submit" class="btn small-btn" name="" value="訂閱" />
			</form>
			</div>
				
			<!-- Start Column -->	
			<div class="fourth widget last footer-action">
				<h3>行動參與，挺好的！</h3>
				<ul>
					<li><a href="#">捐款給綠黨</a></li>
					<li><a href="#">成為志工</a></li>
					<li><a href="#">加入黨員</a></li>					
					<li><a href="#">合作提案</a></li>
				</ul>
			</div>
			
		</div>
	</div>
	<!-- End Widget Footer -->			
				
	
	
	
	<!-- /////////////////// --> 
	<!-- Start Footer -->
	 <footer class="outter-wrapper feature">
			<div class="wrapper">
			<div class="clearfix">
				<div class="foot right">
					<!-- Social Media icons -->
					<ul class="social-link">
						<li><a href="https://www.facebook.com/taiwangreenparty" target="_blank"><?=$user['title']?>選舉動態首頁</a></li>
						<li>｜</li>						
						<li><a href="https://www.facebook.com/taiwangreenparty" target="_blank"><em class="icon-facebook-sign"></em> 綠黨粉絲團</a></li>
					</ul>
				</div>	
				<!-- Copyright Info -->				
				<div class="foot left">&copy; Copyright Green Party Taiwan 2014</div>
			</div>
			</div>
	 </footer> 	
	 <!-- End Footer -->
    
		
	<!-- /////////////////// --> 
	<!-- Start Scripts -->
		<!--<script type="text/javascript" src="js/vendor/jquery-1.8.3.min.js"></script>-->
	<script src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>
		        				
	<script type="text/javascript" src="js/fitvids.min.js"></script>
	<script type="text/javascript" src="js/fancybox/jquery.fancybox.js?v=2.1.4"></script>
	<script type="text/javascript" src="js/placeholder.js"></script>
	<script type="text/javascript" src="js/jquery.flexslider-min.js"></script>
	<script type="text/javascript" src="js/mosaic.1.0.1.min.js"></script>
	<script type="text/javascript" src="js/cleantabs.jquery.js"></script>

	<script type="text/javascript" src="rs-plugin/js/jquery.themepunch.plugins.min.js"></script>
	<script type="text/javascript" src="rs-plugin/js/jquery.themepunch.revolution.min.js"></script>
	<script type="text/javascript" src="js/rs-slider.js"></script>

	<script type="text/javascript" src="js/contact.js"></script>
	<script type="text/javascript" src="js/jquery.form.js"></script>
	<script type="text/javascript" src="js/jquery.validate.min.js"></script>
	<script type="text/javascript" src="js/twphone.js"></script>

	<script type="text/javascript" src="js/jquery.stellar.min.js"></script>
	<script type="text/javascript" src="js/jquery.scrollUp.min.js"></script>
	<script type="text/javascript" src="js/selectivizr-min.js"></script>
	
	<script src="js/kkcountdown.min.js" type="text/javascript"></script>
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

	<script type="text/javascript" src="js/fittext.js"></script>	
    <script type="text/javascript">
		// FitText.js
		fitText(document.getElementById('promise'), 0.83)
	</script>
	<script type="text/javascript" src="js/main.js?<?=time?>"></script>
    <script type="text/javascript" src="timeline/files/javascript/timeline.js"></script>			

 
	</body>
</html>