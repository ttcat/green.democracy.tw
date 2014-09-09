<?php 
if(!$user['banner'])
{
	$user['banner'] = '/images/1920x2.jpg';
}
?>
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
    	
    	<div class="feature-heading"><a href="/<?php echo $u?>">

    		<?php if($user['slogan']) { ?><p class="heading"><?php echo $user['slogan']?></p><?php } ?>
	    		<p><?php echo $user['title']?>
    					<?php if(!$detect->isMobile()) { ?><?php if($user['fb']) { ?><div class="fb-like main-like" data-href="<?php echo $user['fb']?>" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div><?php }  } ?>
		    	<?php if($user['section'] or $user['detail']) { ?><ul class="heading-info">
		    			<?php if($user['section']) { ?><li><?php echo $user['section']?></li><?php } ?>
		    			<?php if($user['detail']) { ?><li><?php echo $user['detail']?></li><?php } ?>
    				<ul><?php } ?>
    			</p>

    	</a></div>
    	
    	</div>

		<div class="bannerShadow" style="background-image: url(<?php echo $user['banner']?>);"></div>

    	<div class="outer-profile-img">
			<?php if($detect->isMobile()) {?> <?php if($user['fb']) { ?><div class="fb-like phone-like" style="position: absolute;" data-href="<?php echo $user['fb']?>" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div> <?php } } ?>    	
		    <img id="imgHeadShot" class="profile-img" src="<?php echo $user['logo']?>" alt="<?php echo $user['title']?>">
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
    	    	
    	    	<a href="/<?php echo $u?>" class="logo"><img src="/images/gp_badge.png?v2" alt="Logo" /> <span id="logo-word"></span></a>
    	        <span class="stickname" id="thisname"><?php echo $user['title']?></span>
    	    	
    	        <nav id="nav-wrap">
    	        	<ul class="nav" id="nav">
    	        	
    	            	<li class="nav-parent"><a href="/<?php echo $u?>/bio" id="first-nav">認識<?php echo $user['title']?></a>
							<ul>
		    	                <li><a href="/<?php echo $u?>/bio">簡介</a></li>
    			                <li><a href="/<?php echo $u?>/issues">政見</a></li>
		    	                <!--<li><a href="#">政治代理人公約</a></li>-->
		    	                <li><a href="/<?php echo $u?>/endorsements">各界推薦</a></li>
    			                <!--<li><a class="nav-parent" href="#">活動行程</a></li>-->
    			            </ul>
    			        </li>
    	            	<li class="nav-parent last donate"><a href="<?php echo $user['fundlink']?>"><em class="fa fa-heart"></em> <?php if($user['fundraising']) { ?>捐款<?php }else{ ?>行動<?php } ?>支持</a>
    	            		<ul style="overflow: hidden;">
    	            		    <?php if($user['fundraising']) { ?><li><a href="<?php echo $user['fundlink']?>">線上捐款</a></li><?php } ?>
    	            			<?php if($user['gembeded']) { ?><li><a href="/<?php echo $u?>/finance">捐款徵信</a></li><?php } ?>
<!--
    	            			<li><a href="#">承諾投票</a></li>
    	            			<li><a href="#">成為志工</a></li>
-->
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