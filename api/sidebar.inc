				<aside class="right-aside fourth last">
			    	
			    	<? if($user['issues'] && $user['policy']) 
			    		{
			    		$user['policy'] = explode('|', $user['policy']);			    		
			    		$user['policyicon'] = explode('|', $user['policyicon']);
			    		
			    	 ?>
				    	<div class="clearfix aside-focus">
                			<h3><strong>主要關注</strong></h3>
                			<ul class="statistics">
                			<? foreach($user['policy'] as $key => $v) { ?>
                				<li><em class="fa <?=$user['policyicon'][$key]?>"></em> <span<? if($key > 0) { ?> style="color:black;"<? } ?>><?=$v?></span></li>
                			<? } ?>
                			</ul>	
                			<p><a class="more" herf="/<?=$u?>/issues">了解目前的政見</a></p>
                		</div>
				    <? } ?>
				    
				    	                		
			    	<? if($user['recommendation']) { ?>                		
                		<!-- Quote Widget -->
				    	<div class="clearfix aside-recom">
                			<h3><strong>各界推薦</strong></h3>
                			<blockquote><?=$recommendation[0]['node']['content']?><cite>- <?=$recommendation[0]['node']['title']?> / <?=$recommendation[0]['node']['professional-title']?></cite></blockquote>
                		</div>
					<? } ?>	
					
			    	<? if($user['fundraising']) { ?>                		
				    	<div class="clearfix aside-donate">
                			<h3><strong>捐款支持</strong></h3>
                			<p><?=$user['fundtitle']?></p>
							<? /*
                			<ol class="graphs">
                				<li><div class="per-60 btn-style2"> 1,203,234<span>60%</span></div></li>                				
                			</ol>
                			*/?>        			
                			<a href="<?=$user['fundlink']?>" class="btn small-btn "><em class="fa fa-heart"></em>線上捐款</a><p></p>
                		</div>	

                	<hr>
					<? } ?>

			    	<? if($user['gotv']) { ?>                		

                		<!-- Email Signup Widget -->
				    	<div class="clearfix aside-signup">
                			<h3 id="promise"><strong>承諾 <span time="1417219200" class="petition_count kkcount-down"></span> 天後投票</strong></h3>
                			<p>登記為本選區的選民、訂閱且隨時關注<?=$user['title']?>最新消息，並承諾在 <span class="highlight">11/29</span> 一定去投票！</p>
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
			    	
					<? } ?>

			    	<? if($user['news']) { ?>                		

                		<!-- Start Text Widget -->     
				    	<div class="clearfix aside-news">
                			<h3><strong>相關新聞</strong></h3>
                			<div class="mosaic-block fade">
                				<a href="#" class="mosaic-overlay link" title="新聞標題"></a><div class="mosaic-backdrop">
                				<div class="corner-date">8/26</div><img src="/img/small_thumb3.jpg" alt="Mock" /></div>
                			</div>
                			<h3 class="title"><a href="#">新聞標題</a></h3>
                			<p>媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息媒體曝光的消息
                			&#8230;<a class="more">更多</a></p>
                		</div>
                		
                <hr class="aside-news">
                <? } ?>
                
                
				<? if($user['gallery']) { ?>                		                		
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
				<? } ?>
				
				
			    	
				    	<div class="clearfix aside-contact">
				    	
                			<h3><strong>聯繫<?=$user['title']?></strong></h3>
							<? if($user['fb']) { ?><div class="fb-like-box" style="margin-left: -10px; margin-bottom: 5px; margin-top: -5px;" data-href="<?=$user['fb']?>" data-width="200" data-colorscheme="light" data-show-faces="false" data-header="false" data-stream="false" data-show-border="false"></div><? } ?>
							<ul class="link-list">
    	       					<? if($user['website']) { ?><li><a href="#">網站名稱</a></li><? } ?>
    	       					<? if($user['phone']) { ?><li><a href="tel:<?=$user['phone']?>"><?=$user['phone']?></a></li><? } ?>
    	       					<? if($user['address']) { ?><li><a href="https://www.google.com.tw/maps/search/<?=$user['address']?>/?hl=zh-TW" target="blank"><?=$user['address']?></a></li><? } ?>
    	       					
    	       					<? if($user['email']) { ?><li><a href="emailto:<?=$user['email']?>"><?=$user['email']?></a></li><? } ?>
    	       				</ul>
                		</div>
			    	
			    	
			    		<a href="#" target="_blank">回到選舉動態首頁</a>

			    			    	
				</aside> 