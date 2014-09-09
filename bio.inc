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
				

				<!-- add here-->
				<h2><?php echo $user['title']?>的簡介</h2>
						<hr>

						<div>
							<p>

													
<!--								<strong>自傳標題</strong></br></br>
							
							<div class="half">
		                       	<img src="<?php echo $user['logo']?>" alt="mock" width="100%">
	    	                   	<span class="wp-caption-text">參與社會運動的過程</span>
	        	            </div>
	                    
	            	        被監督人 張明麗君 對於食安議題關注甚深、熱心公益，在基隆七堵地區推動共同購買，為本社基隆市七堵區綠葉山莊共同購買班創班班長，同時為本社解說員、基隆地區社員代表；平日在組織活動中，對於綠色生活之觀念皆能實踐、身體力行。<br/></br>
							該君為實踐公民參政理想，並將食農議題、永續環境理念廣佈於基隆地區，決定代表綠黨投入2014年基隆市市議員選舉，作為一個長期關注台灣食農議題的社運團體，我們樂觀其成，並願意扮演監督者的角色，與社會各界共同監督，真正落實公民參政的理念。<br/></br>此致<br/></br>

    	                	</p> -->
						</div>


								<?php print_r($user['bio']); ?>
								

				<h2 class="clearfix">經歷</h2>
						<hr>

						<?php $ex = explode('|', $user['bio']); ?>

						<div>
						<p>
						<ul>
							<?php foreach ($ex as $key => $value) { ?>
							<?php if($vaule) { ?><li><?php echo $value; ?></li><?php } ?>
							<?php } ?>
						</ul>
						</p>
						</div>

				<br>
												
				<h2 class="clearfix">政治獻金專戶</h2>
						<hr>

						<div>
						<p>
						<ul>
							<?php if($user['accountnumber']) { ?><li>帳號：<?php echo $user['accountnumber']?></li><?php } ?>
							<?php if($user['accountname']) { ?><li>戶名：<?php echo $user['accountname']?></li><?php } ?>
							<?php if($user['bank']) { ?><li>銀行：<?php echo $user['bank']?><?php } ?>
							<?php if($user['banknumber']) { ?><li>代碼：<?php echo $user['banknumber']?></li><?php } ?>
						</ul>
						</p>
						</div>

				<br>
	
				<h2 class="clearfix">聯絡資訊</h2>
						<hr>

						<div>
						<ul>
							<?php if($user['address']) { ?><li>地址：<?php echo $user['address']?></li><?php } ?>
							<?php if($user['phone']) { ?><li>電話：<?php echo $user['phone']?></li><?php } ?>
							<?php if($user['email']) { ?><li>聯絡 email：<?php echo $user['email']?></li><?php } ?>
						</ul>
						<br>
						<iframe width="100" height="550" src="https://www.google.com/maps/embed?pb=!1m14!1m8!1m3!1d3683.04753595446!2d120.299208!3d22.614699999999996!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x346e037fbc0131fd%3A0x9697296bace77b26!2zODAy6auY6ZuE5biC6IuT6ZuF5Y2A6I-v5paw6KGXMeiZnw!5e0!3m2!1szh-TW!2stw!4v1409090033264" style="border:0"></iframe>
						
						
						</div>
						
    	                    	                    	                    	                    	                
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
