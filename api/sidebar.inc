				<aside class="right-aside fourth last">
			    	
			    	<?php if($user['issues'] && $user['policy'][0])
			    		{			    					    		
			    	 ?>
				    	<div class="clearfix aside-focus">
                			<h3><strong>主要關注</strong></h3>
                			<ul class="statistics">
                			<?php
                			
                			$policyicon = explode('|', $user['policyicon']); 
                			
                			 foreach($user['policy'] as $key => $v) { ?>
                				<li><?php if($policyicon) { ?><em class="fa <?php echo $policyicon[$key]?>"></em> <?php } ?><span<?php if($key >= 0) { ?> style="color:black;"<?php } ?>><?php echo $v?></span></li>
                			<?php } ?>
                			</ul>	
                			<p><a class="more" href="/<?php echo $u?>/issues">了解目前的政見</a></p>
                		</div>
				    <?php } ?>
				    
				    	                		
			    	<?php if($user['recommendation'] && $section != 'endorsements' && $recommendation[0]['node']['nid']) { ?>                		
                		<!-- Quote Widget -->
				    	<div class="clearfix aside-recom">
                			<h3><strong>各界推薦</strong></h3>
                			<blockquote><?php if($recommendation[0]['node']['short-content']) { echo $recommendation[0]['node']['short-content']; } else { echo SL(strip_tags($recommendation[0]['node']['content']), 60); } ?><a href="/<?php echo $u;?>/endorsements/<?php echo $recommendation[0]['node']['nid']; ?>"> <i style="font-size:13px;">(閱讀全文)</i><cite>- <?php echo $recommendation[0]['node']['title']?> / <?php echo $recommendation[0]['node']['professional_title']?></cite></a></blockquote>
                		</div>
					<?php } ?>	
					
			    	<?php if($user['fundraising'] && $user['accountnumber']) { 
			    	
			    			if(!$user['fundtitle']) { $user['fundtitle'] = "您的捐款，可以讓我們印製更多文宣、增加輔選宣傳的人力，讓更多市民認識綠黨、認識{$user['title']}的政見！"; }
			    	?>                		
				    	<div class="clearfix aside-donate">
                			<h3><strong>捐款支持</strong></h3>
                			<p><?php echo $user['fundtitle']?></p>
							<?php /*
                			<ol class="graphs">
                				<li><div class="per-60 btn-style2"> 1,203,234<span>60%</span></div></li>                				
                			</ol>
                			*/?>        			
                			<a href="<?php echo $user['fundlink']?>" onClick="_gaq.push(['_trackEvent', 'donate_sidebar', '<?php echo $u;?>', 'sidebar']);" target="_blank" class="btn small-btn "><em class="fa fa-heart"></em>線上捐款</a><p></p>
                		</div>	

                	<hr>
					<?php } ?>

			    	<?php if($user['gotv'] && $done == 1) { ?>                		

                		<!-- Email Signup Widget -->
				    	<div class="clearfix aside-signup">
                			<h3 id="promise"><strong>承諾 <span time="1417219200" class="petition_count kkcount-down"></span> 天後投票</strong></h3>
                			<p>登記為本選區的選民、訂閱且隨時關注<?php echo $user['title']?>最新消息，並承諾在 <span class="highlight">11/29</span> 一定去投票！</p>
                			<form id="contactform" class="quick-contact" action="php/processForm.php" method="post">                			
                				<table class="tableless">
                					<tr><td><input type="text" id="name" name="name" placeholder="姓名" /></td></tr>
                					<tr><td><input type="email"id="email" name="email" placeholder="Email" value="" /></td></tr>
                					<tr><td><input type="text" id="phone" name="phone" placeholder="手機號碼" value="" maxlength="10" /></td></tr>                					
                					<tr><td><input type="text" id="message" name="message" placeholder="選區，例如%高雄市三民區%"></td></tr>
                					<tr><td>
									<input name="button" class="btn small-btn" type="submit" value="送出" id="send" /><br/></td></tr>
                				</table>
                			</form>
                			<div id="response"></div>
                		</div>
                					    	
			    	<hr/>
			    	
	<script type="text/javascript" src="/js/fittext.js"></script>	
    <script type="text/javascript">
		// FitText.js
		fitText(document.getElementById('promise'), 0.83)
	</script>
			    	
					<?php  } ?>



			    	<?php if($user['news'] && $done == 1) { ?>                		

                		<!-- Start Text Widget -->     
				    	<div class="clearfix aside-news">
                			<h3><strong>相關新聞</strong></h3>
                			<div class="mosaic-block fade">
                				<a href="#" class="mosaic-overlay link" title="<?php echo $news[0]['title']; ?>"></a><div class="mosaic-backdrop">
                				<div class="corner-date">8/26</div><img src="<?php echo $news[0]['title']; ?>" alt="Mock" /></div>
                			</div>
                			<h3 class="title"><a href="#">新聞標題</a></h3>
                			<p>媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息
                			&#8230;<a class="more">更多</a></p>
                		</div>
                		
                <hr class="aside-news">
                <?php } ?>
                
                
				<?php if($user['gallery'] && $done == 1) { ?>                		                		
			    	<!-- Start Gallery Widget -->
			    	
			    	<div class="clearfix gallery aside-gallery">

                	<h3><strong>Gallery</strong></h3>

			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half fade">
			    			<a href="/img/thumb-1.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="/img/thumb-1.jpg" alt="Start" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->	
			    		<div class="mosaic-block half last fade">
			    			<a href="/img/thumb-2.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="/img/thumb-2.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half fade">
			    			<a href="/img/thumb-3.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="/img/thumb-3.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half last fade">
			    			<a href="/img/thumb-4.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="/img/thumb-4.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->
			    		<div class="mosaic-block half fade">
			    			<a href="/img/thumb-5.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="/img/thumb-5.jpg" alt="Mock" /></div>
			    		</div>
			    		
			    		<!-- Start thumbnail -->	
			    		<div class="mosaic-block half last fade">
			    			<a href="/img/thumb-6.jpg" class="mosaic-overlay fancybox" data-fancybox-group="SidebarGallery" title="Insert Your Title"></a>
			    			<div class="mosaic-backdrop"><img src="/img/thumb-6.jpg" alt="Mock" /></div>
			    		</div>
			    			
			    			
						<p><a class="more">更多</a></p>
	
			    	</div>

                <hr class="aside-gallery">                		
				<?php } ?>
				
				
			    	
				    	<div class="clearfix aside-contact">
				    	
                			<h3><strong>聯繫<?php echo $user['title']?></strong></h3>
							<?php if($user['fb']) { ?><div class="fb-like-box" style="margin-left: -10px; margin-bottom: 5px; margin-top: -5px;" data-href="<?php echo $user['fb']?>" data-width="200" data-colorscheme="light" data-show-faces="false" data-header="false" data-stream="false" data-show-border="false"></div><?php } ?>
							<ul class="link-list">
    	       					<?php if($user['website']) { ?><li><a href="#">網站名稱</a></li><?php } ?>
    	       					<?php if($user['phone']) { ?><li><a href="tel:<?php echo $user['phone']?>"><?php echo $user['phone']?></a></li><?php } ?>
    	       					<?php if($user['address']) { ?><li><a href="https://www.google.com.tw/maps/search/<?php echo $user['address']?>/?hl=zh-TW" target="blank"><?php echo $user['address']?></a></li><?php } ?>
    	       					
    	       					<?php if($user['email']) { ?><li><a href="emailto:<?php echo $user['email']?>"><?php echo $user['email']?></a></li><?php } ?>
    	       				</ul>
                		</div>
			    	
			    	
			    		<?php if($section != 'politician') { ?><a href="<?php echo WEB.'/'.$u; ?>">回到<?php echo $user['title']; ?>選舉動態首頁</a><?php } ?><br /><br />

			    			    	
				</aside> 
