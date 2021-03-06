<?php
// declare global for compatibility reason
global $u,$nid;

// timeline
// re-use api

require_once('api/timeline.inc');
$string = get_timeline(FALSE);

$newsfeeds = json_decode($string,true);
$newsfeeds_perpage = $newsfeeds[0]['perpage'];
$newsfeeds_total = $newsfeeds[0]['total'];
$newsfeeds_thispage = $newsfeeds[0]['thispage'];

$object = $newsfeeds;

?><!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
    <head>
<?php require_once 'api/meta.inc'; ?>
         <link rel="stylesheet" type="text/css" href="/css/normalize.min.css">
         <link rel="stylesheet" type="text/css" href="/css/main.css?<?php echo time(); ?>">
         <link rel="stylesheet" type="text/css" href="/css/responsive.css?<?php echo time(); ?>">
         <link rel="stylesheet" type="text/css" href="/timeline/files/css/timeline_themegp.css?<?php echo time(); ?>" />         
         <link rel="stylesheet" type="text/css" href="/css/flexslider.css">
         <link rel="stylesheet" type="text/css" href="/css/font-awesome.css">
         <link rel="stylesheet" type="text/css" href="/js/fancybox/jquery.fancybox.css?v=2.1.4" media="screen" />
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

        <div id="timeline" style="margin-top:20px; margin-bottom:20px;" class="timeline"></div>
		<div class="timeline_loadmore" id="loadmore" style="display:none;">
    		<em class="fa fa-refresh"></em> 顯示更多
    	</div>

<?php if($show_nid_one) { ?>
		<div class="timeline_loadmore" id="loadall">
    		<a href="http://green.democracy.tw/<?php echo $u; ?>" style="display:block; color:white;"><em class="fa fa-refresh"></em> 顯示全部</a>
    	</div>
<?php } ?>
				<!-- add here-->


                </div>
				
				<!-- Start Main Sidebar  -->
					<?php require_once 'api/sidebar.inc'; ?>
				<!-- Finish Sidebar -->

        	</div> <!-- #main -->
        </div> <!-- #main-container -->
    </div>	


					<?php require_once 'api/footer.inc'; ?>


		
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

	<script type="text/javascript" src="/js/contact.js"></script>
	<script type="text/javascript" src="/js/jquery.form.js"></script>
	<script type="text/javascript" src="/js/jquery.validate.min.js"></script>
	<script type="text/javascript" src="/js/twphone.js"></script>

	<script type="text/javascript" src="/js/jquery.stellar.min.js"></script>
	<script type="text/javascript" src="/js/jquery.scrollUp.min.js"></script>
	<script type="text/javascript" src="/js/selectivizr-min.js"></script>
	<script  type="text/javascript" src="/js/jquery.sticky-kit.min.js"></script>	
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

<?php if($user['gotv'] && $done == 1) { ?>
	<script type="text/javascript" src="/js/fittext.js"></script>	
    <script type="text/javascript">
		// FitText.js
		fitText(document.getElementById('promise'), 0.83)
	</script>
<?php } ?>	
	<script type="text/javascript" src="/js/main.js?<?php echo time(); ?>"></script>

    <script type="text/javascript" src="/timeline/files/javascript/timeline.js"></script>			
	<script type="text/javascript" src="/js/jquery-scrollto.js?<?php echo time(); ?>"></script>

        <script type="text/javascript">
            $(document).ready(function() {

                var perpage = <?php echo $newsfeeds_perpage; ?>;
                var init_data = <?php echo $string; ?>;

				var total_feeds = <?php echo $newsfeeds_total; ?>; 
				var feeds_left = total_feeds - perpage;
				var columnMode_t = 'dual';
				
							if(feeds_left <= 0) {
				                $('#loadmore').css('display', 'none');
							}else{
				                $('#loadmore').css('display', 'block');
							}							
								
				<?php if($show_nid_one) { ?>
			        columnMode_t = 'right'; 
					$('#loadall').css('display', 'block');
        		<?php }else{ ?>
				
				var rwd_js = $(window).width();
				if(rwd_js < 770) { columnMode_t = 'right';} else { columnMode_t = 'dual'; }
				
				<?php } ?>
                var timeline = new Timeline($('#timeline'), init_data);
                timeline.setOptions({
                	<?php if(!$show_nid_one) { ?>responsive_width : 770,<?php } ?>
                    animation:       true,
                    lightbox:        true,
                    first_separator: false,
                    separator:       'null',
                    columnMode:  columnMode_t,
                    order:           'desc',
                    height:			400,
                    loadmore: feeds_left,
                });
                timeline.display();

                // load more click
                var page = 1;
                
                $('#loadmore').on('click', function(e) {
                    var button = $(this);
                    if (button.hasClass('notice')) {
                        return;
                    }
                    
                    page++;
                    
                    button.addClass('notice').text('讀取中...');

                    $.ajax('/<?php echo $u; ?>/timeline?p='+page, {
                        type     : 'GET',
                        dataType : 'json',
                        success  : function(data) {
                            // remove loading
							button.css('display', 'none');                            
                            button.removeClass('notice').html('<em class="fa fa-refresh"></em> 顯示更多');
                            // append new data
                            timeline.appendData(data);
							feeds_left = feeds_left - perpage;

							window.addthis.toolbox(".addthis_sharing_toolbox");
							
							
							if(feeds_left <= 0) {
								button.css('display', 'none');
							}else{
								button.css('display', 'block');
							}							
				
                        }
                    });
                });
                
                
        <?php if($show_nid_one) { ?>
					agoto = '.main-content';
					var agotoy = $(agoto).offset(); 
					$("body").animate({ scrollTop: agotoy.top-100 }, 2000);
					console.log( agotoy );
				<?php } ?>
                
            });
        </script>
	</body>
</html>
