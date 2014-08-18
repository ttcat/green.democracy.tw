<?php
require_once 'api/api.inc';

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
				<h2>各界推薦</h2>
						<hr>
						
			    	<? if($endorsment) { 
			    			$total_en = count($endorsment);
			    			$v = 0;
			    		
			    		foreach ($endorsment as $key => $en) {
			    			
			    			$v ++;
				    		$en = $en['node'];
			    	?>                		
						
						<p>
						<blockquote>
						<strong>公民參政共同監督意願書</strong></br></br>
						
						<div class="half">
	                       	<img src="<?=$en['photo']?>" alt="mock" width="100%">
	                       	<span class="wp-caption-text">photo desc</span>
	                    </div>
	                    <?=$en['content']?>
						<cite>- <?=$en['title']?> / <?=$en['professional-title']?></cite>
    	                </blockquote>
    	                </p>
					<? if($v < $total_en) { ?><hr><? } ?>

					<? } //end foreach
					} //end if?>
				
    	                    	                    	                    	                    	                
				<!-- add here-->
				</div>
				
				
				
				<!-- Start Main Sidebar  -->
					<? require_once 'api/sidebar.inc'; ?>
				<!-- Finish Sidebar -->

        	</div> <!-- #main -->
        </div> <!-- #main-container -->
    </div>	

					<? require_once 'api/footer.inc'; ?>
					
					
	<!-- Start Scripts -->
	<!--<script type="text/javascript" src="/js/vendor/jquery-1.8.3.min.js"></script>-->
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

 
	</body>
</html>
