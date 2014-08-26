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
    	<div class="wrapper">
    	
    	<div class="feature-heading"><a href="/<?=$u?>">

    		<? if($user['slogan']) { ?><p class="heading"><?=$user['slogan']?></p><? } ?>
	    		<p><?=$user['title']?>
    					<? if(!$detect->isMobile()) {?><div class="fb-like main-like" data-href="<?=$user['fb']?>" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div><? } ?>
		    	<? if($user['section'] or $user['detail']) { ?><ul class="heading-info">
		    			<? if($user['section']) { ?><li><?=$user['section']?></li><? } ?>
		    			<? if($user['detail']) { ?><li><?=$user['detail']?></li><? } ?>
    				<ul><? } ?>
    			</p>

    	</a></div>
    	
    	</div>

		<div class="bannerShadow" style="background-image: url(<?=$user['banner']?>);"></div>

    	<div class="outer-profile-img">
			<? if($detect->isMobile()) {?> <div class="fb-like phone-like" style="position: absolute;" data-href="<?=$user['fb']?>" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div> <? } ?>    	
		    <img id="imgHeadShot" class="profile-img" src="<?=$user['logo']?>" alt="<?=$user['title']?>">
	    </div>
    	
    </div>
        
    <!-- End Outter Wrapper -->		

	<div id="sticky-anchor"></div>
    <!-- Start Outter Wrapper -->
    <div id="navall" class="outter-wrapper header-container">
    
    	<!-- Start Main Navigation -->
    	<div class="wrapper">
    	    <header class="clearfix">

    	    	<!--<a href="index.html" class="logo"><img src="/images/gp_badge.png?v2" alt="Logo" /> <span>綠黨政治代理人公約</span></a>-->
    	    	
    	    	<a href="/<?=$u?>" class="logo"><img src="/images/gp_badge.png?v2" alt="Logo" /> <span id="logo-word"></span></a>
    	        <span class="stickname" id="thisname"><?=$user['title']?></span>
    	    	
    	        <nav id="nav-wrap">
    	        	<ul class="nav" id="nav">
    	        	
    	            	<li class="nav-parent"><a href="/<?=$u?>/bio" id="first-nav">認識<?=$user['title']?></a>
							<ul>
		    	                <li><a href="/<?=$u?>/bio">簡介</a></li>
    			                <li><a href="/<?=$u?>/issues">政見</a></li>
		    	                <!--<li><a href="#">政治代理人公約</a></li>-->
		    	                <li><a href="/<?=$u?>/endorsements">各界推薦</a></li>
    			                <li><a class="nav-parent" href="#">活動行程</a></li>
    			            </ul>
    			        </li>
    	                
    	            	<li class="nav-parent last donate"><a href="<?=$user['fundlink']?>"><em class="fa fa-heart"></em> 捐款支持</a>
    	            		<ul style="overflow: hidden;">
    	            		    <li><a href="<?=$user['fundlink']?>">線上捐款</a></li>
    	            			<li><a href="/<?=$u?>/finance">捐款徵信</a></li>
<? /*    	            			<li><a href="#">承諾投票</a></li>
    	            			<li><a href="#">成為志工</a></li> */ ?>
    	            			<li><a href="javascript:fb();">分享給朋友</a></li>
    	            		</ul>
    	            	</li>
    	                
    	                
    	            </ul>                	
    	        </nav>
    	    </header>
    	</div>
    	<!-- End Main Navigation -->
    </div>
    <!-- End Outter Wrapper -->
    
    <div id="space"></div>