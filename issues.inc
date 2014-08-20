<?php
global $u;
global $nid;

require_once 'api/api.inc';

//政見
$string = file_get_contents("http://v.democracy.tw/{$u}/issue.json");
$issues = json_decode($string, true);
$issues = $issues['nodes'];

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
				<h2>政見</h2>
				
				<hr>
				
				<ul class="issues toggle">

						<? foreach ($issues as $key => $value) { 
							$issue = $value['node']; 
						?>
    	                		<!-- Toggle -->
    	                	    <li class="toggle-li">
    	                	      <a href="#" class="toggle-btn" hash-id="<?=$issue['nid']?>" id="sa<?=$issue['nid']?>"><em class="icon-globe"></em> <span><?=$issue['title']?></span></a>
    	                	      <div class="toggle-content">

    	                	      	<p><?=$issue['content']?></p>

									<p><span class="issues-tags meta"><span class=" icon-tags"></span> <?=$issue['tag']?><span></p>
									

    	                	      </div>
    	                	    </li>
    	                <? } ?>	    
    	                	    
    	                	    <!-- Toggle -->
    	                	    <li class="toggle-li">
    	                	      <a href="#" class="toggle-btn" hash-id="21" id="sa21">My Credit Card Is Stuck In My Computer?</a>
    	                	      <div class="toggle-content">

	    	                	      <h6>Heading Six <span>Span</span></h6>
										<ol>
    			                       		<li>Cras justo odio, dapibus</li>
    	        		               		<li>Donec ullamcorper nulla non metus auctor fringilla</li>
    	        		               		<li>因為：
												<ol>
	    				                       		<li>Cras justo odio, dapibus</li>
    	        				               		<li>Donec ullamcorper nulla non metus auctor fringilla</li>
    	        				               	</ol>
    	        		               		</li>
    	        		               		
    	                		       	</ol>
    	                       		    	                	      
    	                	      	<p>Donec ullamcorper nulla non metus auctor fringilla. Aenean eu leo quam. Pellentesque ornare sem lacinia quam venenatis vestibulum. Cras mattis consectetur purus sit amet fermentum. Aenean eu leo quam. Pellentesque ornare sem lacinia quam venenatis vestibulum. Duis mollis, est non commodo luctus, nisi erat porttitor ligula, eget lacinia odio sem nec elit.</p>
    	                	      	
    	                	      	<p class="fluid-width-video-wrapper" style="height:100%; min-height:300px;"><iframe src="http://player.vimeo.com/video/51014619?color=ffffff" id="fitvid972851"></iframe></p>
    	                	      	
    	                	      	
    	                	      </div>
    	                	    </li>

    	                	  </ul>

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
	<script type="text/javascript" src="/js/purl.js"></script>
	
	<script type="text/javascript" src="/js/main.js?<?=time?>"></script>
									
        <script type="text/javascript">
            $(document).ready(function() {

            
            	var agoto;

            	current_nid = '<?=$nid?>';
            	
	            if(current_nid) {

					$( ".issues > li" ).each(function( index ) {
						  
						var lia = $( this ).find('a');
						//console.log( index + ": " + lia.attr('hash-id') );

					  if(lia.attr('hash-id') == current_nid) {
					  	
					  	lia.addClass('active');
					  	$(this).find('div').css('display', 'block'); 
						
					  }else{
					  	lia.removeClass('active');
					  	$(this).find('div').css('display', 'none');  					  
					  	
					  }
					  
					})
					
				}

				if(current_nid) { 
					agoto = '#sa' + current_nid;
					var agotoy = $(agoto).offset(); 
					$('body').scrollTo(agotoy.top-200, {duration:800}).delay( 800 );
					console.log( agotoy );
				}
			});


$.fn.scrollTo = function( target, options, callback ){
  if(typeof options == 'function' && arguments.length == 2){ callback = options; options = target; }
  var settings = $.extend({
    scrollTarget  : target,
    offsetTop     : 50,
    duration      : 500,
    easing        : 'swing'
  }, options);
  return this.each(function(){
    var scrollPane = $(this);
    var scrollTarget = (typeof settings.scrollTarget == "number") ? settings.scrollTarget : $(settings.scrollTarget);
    var scrollY = (typeof scrollTarget == "number") ? scrollTarget : scrollTarget.offset().top + scrollPane.scrollTop() - parseInt(settings.offsetTop);
    scrollPane.animate({scrollTop : scrollY }, parseInt(settings.duration), settings.easing, function(){
      if (typeof callback == 'function') { callback.call(this); }
    });
  });
}

                        
        </script>
 
	</body>
</html>
