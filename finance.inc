<?php
require_once 'api/api.inc';

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
    	
	<? require_once 'api/header.inc'; ?>
    	
    	
    <div class="outter-wrapper">	
    	 <!-- Start Main Body -->
        <div class="main-container">
            <div class="main wrapper clearfix">
            	<!-- Start Main Content -->				
            	
                <div class="main-content three-fourths">
				

				<!-- add here-->
				<h2>捐款公開徵信</h2>
						<hr>
						
						
						
						<p>
						<iframe style="height:600px;" src="https://docs.google.com/spreadsheets/d/1_0zPlnB8G2hBR4ir7pktNtaod8kTKrgglUpe0BKKWaY/pubhtml?widget=true&amp;headers=false"></iframe>
    	                </p>
	    	                    	                    	                    	                    	                
				<!-- add here-->
				</div>
				
				
				
				<!-- Start Main Sidebar  -->
					<? require_once 'api/sidebar.inc'; ?>
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
