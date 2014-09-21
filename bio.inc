<?php
require_once 'api/api.inc';

//cv
$string = http_request_contents("http://v.democracy.tw/{$u}/timeline.json/cv");

   $cvs =  json_decode($string, true);
	$cvs = $cvs['nodes'];
	$object = $cv;

?><!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
    <head>
<?php require_once 'api/meta.inc'; ?>
         <link rel="stylesheet" type="text/css" href="/css/normalize.min.css">
         <link rel="stylesheet" type="text/css" href="/css/main.css?<?php echo time()?>">
         <link rel="stylesheet" type="text/css" href="/css/responsive.css?<?php echo time()?>">
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
            	
                <div class="main-content three-fourths light-wording-div">
				

<?php if($cvs[0]['node']['content']) { ?>
				<!-- add here-->
				<h2><?php echo $user['title']?>的簡介</h2>
						<hr>

						<div>
							<p>

								<strong><?php echo $cvs[0]['node']['title']?></strong></br></br>
							
							<?php if($cvs[0]['node']['photo']) { ?>
							<div class="half">
		                       	<img src="<?php echo $cvs[0]['node']['photo']?>" alt="mock" width="100%">
	    	                   	<span class="wp-caption-text"><?php $cvs[0]['node']['caption']; ?></span>
	        	            </div>
	                    	<?php } ?>
							<?php 
							
							$allowed_tags = array('a', 'em', 'strong', 'cite', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd','p','br');
							echo filter_xss($cvs[0]['node']['content'], $allowed_tags);  ?>
							
    	                	</p><br/><br/>
    	                	
    	                	<div class="addthis_sharing_toolbox" data-url="http://green.democracy.tw/<?php print $u;?>/bio"></div>
						</div>
	<br>
	<br>
<?php } ?>

<?php if($user['bio']) { ?>
				<h2 class="clearfix">經歷</h2>
						<hr>

						<?php $ex = explode('|', $user['exp']); ?>

						<div>
						<p>
						<ul>
							<?php foreach ($ex as $key => $value) { ?>
								<?php if($value) { ?><li><?php echo $value; ?></li><?php } ?>
							<?php } ?>
						</ul>
						</p>
						</div>
			
				<br>
<?php } ?>				

<?php if($user['bank']) { ?>												
				<h2 class="clearfix">政治獻金專戶</h2>
						<hr>

						<div>
						<p>
						<ul>
							<?php if($user['bank']) { ?><li>銀行：<?php echo $user['bank']?><?php } ?>
							<?php if($user['banknumber']) { ?><li>代碼：<?php echo $user['banknumber']?></li><?php } ?>
							<?php if($user['accountnumber']) { ?><li>帳號：<?php echo $user['accountnumber']?></li><?php } ?>
							<?php if($user['accountname']) { ?><li>戶名：<?php echo $user['accountname']?></li><?php } ?>
						</ul>
						</p>
						</div>

				<br>
<?php } ?>

<?php if($user['email'] || $user['phone'] || $user['address']) { ?>	
				<h2 class="clearfix">聯絡資訊</h2>
						<hr>

						<div>
						<ul>
							<?php if($user['address']) { ?><li>地址：<?php echo $user['address']?></li><?php } ?>
							<?php if($user['phone']) { ?><li>電話：<?php echo $user['phone']?></li><?php } ?>
							<?php if($user['email']) { ?><li>信箱：<?php echo $user['email']?></li><?php } ?>
						</ul>
						
						<?php if($user['address']) { ?>
						<br>
						<iframe width="100" height="550" src="https://www.google.com/maps/embed/v1/place?key=AIzaSyCj9XwcX4eH4azexlMKjhfdCymvMQLQAgg&q=<?php echo $user['address']; ?>" style="border:0"></iframe>
						<?php } ?>
						
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
	<script  type="text/javascript" src="js/jquery.sticky-kit.min.js"></script>	
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
