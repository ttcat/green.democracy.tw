<?php

global $all_users;

foreach($all_users as $k2 => $v2) {
	if($v2 != 'test') {
		$string_array[] = http_request_contents("http://v.democracy.tw/{$v2}/site.json", 60*60);
	}
}	

foreach ($string_array as $key => $value) {
  $user = json_decode($value,true);

  if($user['nodes'][0]['node']) {
  	$user['nodes'][0]['node']['id'] = $all_users[$key];
	$users[] = $user['nodes'][0]['node'];
  }
  
}

shuffle($users);
?>

<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
    <head>

		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<!--[if IE]><meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"><![endif]-->
		<meta content="width=device-width, initial-scale=1, maximum-scale=1" name="viewport">
		<meta content="black" name="apple-mobile-web-app-status-bar-style">

		<title>2014 挺好的！綠黨政治代理人</title>
		<meta name="keywords" content="綠黨,挺好的,九合一,選舉,greenparty" />
		<meta property="og:title" content="2014 挺好的！綠黨政治代理人" />
		<meta property="og:type" content="website"/>
		<meta property="og:url" content="http://green.democracy.tw/" />
		<meta property="og:image" content="http://green.democracy.tw/images/fbcover.jpg" />
		<meta property="og:site_name" content="2014 挺好的！綠黨政治代理人" /> 
		<meta property="og:description" content="2014 挺好的人選、挺好的政黨、挺好的！台灣綠黨政治代理人官方網站：新政治，從地方開始！今年綠黨的政治代理人分散在全台灣各地，包括台北市文祥里、淡水、三芝、石門、八里、土城、三峽、樹林、鶯歌、基隆七堵、桃園市、中壢、平鎮、新竹東區、竹東、高雄市三民區、澎湖馬公。我們要向住在這些地區的您，推薦我們最好的政治代理人！即使您不住在這些區域，我們也需要您大力的分享推薦給其他朋友！" />  
		<meta property="fb:app_id" content="687618544645054" />
		<meta property="fb:admins" content="100000125299492" />
		<meta property="og:locale" content="zh_TW" />
		<meta property="og:locale" content="zh_TW" />
		<meta property="og:see_also" content="http://greenparty.org.tw/">		
		<link rel="shortcut icon" href="/favicon.ico"/>
		<meta content="#191d24" name="msapplication-TileColor">
		<meta content="/images/fbcover_144.png" name="msapplication-TileImage">
		<link href="http://green.democracy.tw/images/fbcover_144.png" rel="apple-touch-icon-precomposed">

         <link rel="stylesheet" type="text/css" href="/css/normalize.min.css">
         <link rel="stylesheet" type="text/css" href="/css/main.css">
         <link rel="stylesheet" type="text/css" href="/css/responsive.css">
         <link rel="stylesheet" type="text/css" href="/css/flexslider.css">
         <link rel="stylesheet" type="text/css" href="/css/font-awesome.css">
         <link rel="stylesheet" type="text/css" href="/js/fancybox/jquery.fancybox.css?v=2.1.4" media="screen" />
         <script src="/js/vendor/modernizr-2.6.2-respond-1.1.0.min.js"></script>         
<!--GA-->
	<script>
	  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-54051080-1', 'auto');
  ga('send', 'pageview');		
  </script>		
<!--GA-->  
    </head>
    <body>
    	
<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&appId=687618544645054&version=v2.0";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>

    <!--[if lt IE 7]>
        <p class="chromeframe">你的瀏覽器太舊了，請升級或下載 <a href="http://www.google.com/chromeframe/?redirect=true"> Google Chrome Frame </a> 來瀏覽此網站</p>
    <![endif]-->
	


    <!-- Start Outter Wrapper / Feature Image -->	
    <div class="outter-wrapper feature">
		<div class="bannerShadowNone" style="background-image: url('/images/index_banner3.jpg');"></div>    	
    </div>
    
	<div id="sticky-anchor"></div>
    <!-- Start Outter Wrapper -->
    <div id="navall" class="outter-wrapper header-container">
    
    	<!-- Start Main Navigation -->
    	<div class="wrapper">
    	    <header class="clearfix">
    	    	
    	    	<a href="http://green.democracy.tw/" class="logo"><img src="/images/gp_badge.png?v2" alt="Logo" /> <span id="logo-word"></span></a>
    	        <span class="stickname" id="thisname"></span>
    	    	
    	        <nav id="nav-wrap">
    	        	<ul class="nav" id="nav">

						<li><a href="/about">綠黨介紹</a></li>    	        	    	
    	            	<li class="nav-parent last donate"><a href="http://www.greenparty.org.tw/civicrm/contribute/transact?reset=1&id=4"><em class="fa fa-heart"></em> 捐款支持</a>

    	            	</li>
    	        	    	                
    	            </ul>                	
    	        </nav>
    	    </header>
    	</div>
    	<!-- End Main Navigation -->
    </div>
    <!-- End Outter Wrapper -->
    <div id="space"></div>
    	
    <div class="outter-wrapper">	
    	 <!-- Start Main Body -->
        <div class="main-container">
            <div class="main wrapper clearfix">
            	<!-- Start Main Content -->				
            	
                <div class="main-content">


				<h1>2014 綠黨政治代理人</h1>
                	<p class="lead">新政治，從地方開始！今年綠黨的政治代理人分散在全台灣各地，包括<a href="http://green.democracy.tw/antung">台北市文祥里</a>、<a href="http://green.democracy.tw/wangchungming">淡水、三芝、石門、八里</a>、<a href="http://green.democracy.tw/muwan">土城、三峽、樹林、鶯歌</a>、<a href="http://green.democracy.tw/ellen">基隆七堵</a>、<a href="http://green.democracy.tw/rober86">桃園市</a>、<a href="http://green.democracy.tw/chungli2014">中壢</a>、<a href="http://green.democracy.tw/tang">平鎮</a>、<a href="http://green.democracy.tw/jaywin2014">竹東、五峰</a>、<a href="http://green.democracy.tw/star">高雄市三民區</a>、<a href="http://green.democracy.tw/afu">澎湖馬公</a>。我們要向住在這些地區的您，推薦我們最好的政治代理人！若您不住在這些區域，也請您大力的分享推薦給其他朋友！</p>
                	
                	
                	<div class="clearfix">	
                	<?php 
                	
                	$cnt = 1;

                	foreach($users as $key => $user_v) { 
						if($cnt > 1 && $cnt%4 == 0) { $last = "last "; }else{ $last = ""; }
                	?>
                	
                		<a href="/<?php echo $user_v['id']; ?>"><div class="fourth <?php echo $last; ?>boxed">
                			<img src="<?php echo $user_v['logo']; ?>" alt="<?php echo $user_v['title']; ?>" style="width: 500px;" />
                			<div class="inner-box">
                				<h4><?php echo $user_v['title']; ?></h4>
                				<h5><?php echo $user_v['section']?></h5>
                				<em><?php echo $user_v['slogan']?></em>
                				
                				<?php $icons_text = explode('|', $user_v['policy']); $icons = explode('|', $user_v['policyicon']); ?>
                				<ul class="social-link">
                				<?php if($icons_text[0]) { ?>                				
                					<?php /* foreach ($icons as $i => $icon) { ?>
                					<li><a href="#" alt="<?php echo $icons_text[$i]; ?>"><em class="fa <?php echo $icon; ?>"></em></a></li>
                					<?php } */?>
                				<?php } ?>	
                				</ul>
                			</div>
                		</div></a>
                		
					<?php $cnt++;
					}	?>	
                		
                		
                	</div>

				<!-- add here-->
				</div>
				

        	</div> <!-- #main -->
        </div> <!-- #main-container -->
    </div>	


	<?php require_once 'api/footer.inc'; ?>
	
	<!-- Start Scripts -->
	<!--<script type="text/javascript" src="/js/vendor/jquery-1.8.3.min.js"></script>-->
	<script src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>
		        				
	<script type="text/javascript" src="/js/fitvids.min.js"></script>
	<script type="text/javascript" src="/js/fancybox/jquery.fancybox.js?v=2.1.4"></script>
	<script type="text/javascript" src="/js/placeholder.js"></script>
	<script type="text/javascript" src="/js/jquery.flexslider-min.js"></script>
	<script type="text/javascript" src="/js/mosaic.1.0.1.min.js"></script>
	<script type="text/javascript" src="/js/cleantabs.jquery.js"></script>

	<script type="text/javascript" src="/js/contact.js"></script>
	<script type="text/javascript" src="/js/jquery.form.js"></script>
	<script type="text/javascript" src="/js/jquery.validate.min.js"></script>
	<script type="text/javascript" src="/js/twphone.js"></script>

	<script type="text/javascript" src="/js/jquery.stellar.min.js"></script>
	<script type="text/javascript" src="/js/jquery.scrollUp.min.js"></script>
	<script type="text/javascript" src="/js/selectivizr-min.js"></script>
	
	<script type="text/javascript" src="/js/main.js"></script>
 
	</body>
</html>
