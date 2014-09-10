<?php
require_once 'api/api.inc';

?><!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
    <head>
<?php require_once 'api/meta.inc'; ?>
         <link rel="stylesheet" type="text/css" href="/css/normalize.min.css">
         <link rel="stylesheet" type="text/css" href="/css/main.css?<?php echo time()?>">
         <link rel="stylesheet" type="text/css" href="/timeline/files/css/timeline_themegp.css?<?php echo time()?>" />

         <!-- Remove responsive.css is non-responsive needed -->
         <link rel="stylesheet" type="text/css" href="/css/responsive.css?<?php echo time()?>">
         <link rel="stylesheet" type="text/css" href="/css/flexslider.css">
         <link rel="stylesheet" type="text/css" href="/css/font-awesome.css">
         <link rel="stylesheet" type="text/css" href="/js/fancybox/jquery.fancybox.css?v=2.1.4" media="screen" />
         <link rel="stylesheet" type="text/css" href="/rs-plugin/css/settings.css" media="screen" />         
         <script src="/js/vendor/modernizr-2.6.2-respond-1.1.0.min.js"></script>         

    </head>
    <body>
    	
	<?php require_once 'api/header.inc'; ?>
    	
    	
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
						<?php if($user['gembeded'] != '') { ?>
							<iframe style="height:600px;" src="<?php echo $user['gembeded'];?>&amp;headers=false"></iframe>
						<?php } ?>
						
    	                </p>
	    	                    	                    	                    	                    	                
				<!-- add here-->
				</div>
				
				
				
				<!-- Start Main Sidebar  -->
					<?php require_once 'api/sidebar.inc'; ?>
				<!-- Finish Sidebar -->


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

	<script type="text/javascript" src="/js/main.js?<?php echo time?>"></script>		

 
	</body>
</html>
