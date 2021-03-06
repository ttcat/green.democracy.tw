<?php

global $section;

$display_header = Array(

		'bio'=> array('title' => '簡介','desc' => '', 'menu' => '1'),
		'issues'=> array('title' => '政見','desc' => '', 'menu' => '2'),
		'endorsements'=> array('title' => '各界推薦','desc' => '', 'menu' => '3'),
		'events'=> array('title' => '活動行程','desc' => '', 'menu' => '4'),		
		'pledge'=> array('title' => '政治代理人公約','desc' => '', 'menu' => '5'),		
		'finance'=> array('title' => '捐款徵信','desc' => '', 'menu' => '4'),	
		
);

$section_data = $display_header[$section];


$this_url = WEB.'/'.$u.'/'.$section;
if($nid) { $this_url = WEB.'/'.$u.'/'.$section.'/'.$nid; }

if($section == 'politician' && $nid) { 
	//$string_meta = http_request_contents(WEB."/{$u}/timeline?all");
	//$object = json_decode($string_meta,true);
	if($nid) { $this_url = WEB.'/'.$u.'/politician/'.$nid; }else{ $this_url = WEB.'/'.$u; }
}


if($nid && $object) { 

	foreach ($object as $key => $v) {

		if($section == 'politician') { 
		
			if($v['section'] == 'politician') { //section = politician = timeline_news_feed; otherwise go 404.

				$v['node'] = $v; 
				
				if($v['node']['nid'] == $nid) {			

					$v_title = explode('</h3>',$v['node']['content']);
					$nid_name = strip_tags($v_title[0]);
					$nid_desc = SL(strip_tags($v_title[1]), 300);
					
					$fb_title = trim($nid_name) .' - '. $user['title']  . '的' .$v['node']['title'].' | 2014 挺好的！綠黨政治代理人';
					$share_img = "";
					if($v['node']['image']) { $share_img = $v['node']['image']; } //timeline use image as key.
					if($v['node']['photo']) { $share_img = $v['node']['photo']; }
					if($v['node']['videolink']) { $videolink = metavideo($v['node']['videolink'], 0); $videolink_ssl = metavideo($v['node']['videolink'], 1); }
					$nid_found = 1;
										
					$only_this[] = (array) $v['node']; // only show this feed if found;
					$show_nid_one = 1;
					
					$string = json_encode($only_this);	
					$newsfeeds_perpage = 1;
					$newsfeeds_total = 1;
					$newsfeeds_thispage = 0;
										
					
				}
			
			}
			
		}else{
			if($v['node']['nid'] == $nid) {
					$nid_name = $v['node']['title'];
					$nid_desc = SL(strip_tags($v['node']['content']), 150);					
					if($section == 'endorsements') { $nid_desc = $nid_name .'推薦：'.$nid_desc; }
					$fb_title =$nid_name .' - '. $user['title']  . '的' .$section_data['title'].' | 2014 挺好的！綠黨政治代理人';
					if($v['node']['photo']) { $share_img = $v['node']['photo']; }else{ $share_img = ""; }
					if($v['node']['videolink']) { $videolink = metavideo($v['node']['videolink'], 0); $videolink_ssl = metavideo($v['node']['videolink'], 1); }
					$nid_found = 1;
			}
		}
	}
	

  if(!$nid_found) 
  {				
	include("404.html");
	exit();
  }
}


function showFBlike_l($p){
	$url = WEB.$p;
	$fb='<div class="fb-like" data-href="'.$url.'" data-layout="button_count"  data-send="false" data-width="80" data-show-faces="false" data-font="verdana"></div>';
	return $fb;
}


if($section == 'politician' && !$nid) { //index

	$fb_title = $user['title'] .' | 2014 挺好的！綠黨政治代理人';
	$html_title = $fb_title;
	$share_img = $user['logo'];
	$fb_description = $user['title'].'－'.$user['section'].'：'.$user['bio'].'2014 挺好的人選、挺好的政黨、挺好的！台灣綠黨';
 
}else if(!$nid) {	// 沒有帶 nid 的一般單元

	$fb_title = $user['title'].'的'.$section_data['title'].' | 2014 挺好的！綠黨政治代理人';
	if(!$share_img) { $share_img = ""; }
	$html_title = $fb_title;
	if(!$fb_description) $fb_description = $display_header[$section]['desc'];
	
}

if(!$share_link) {	$share_link = $this_url; }
if(!$html_title) {	$html_title = $fb_title; }
if($share_img == '') { $share_img = $user['logo']; }

if($nid_desc) { $fb_description = $nid_desc; }

if(!isset($fb_description) or $fb_description == '') {	$fb_description = $user['title'].'－'.$user['section'].'：2014 挺好的人選、挺好的政黨、挺好的！台灣綠黨政治代理人官方網站。'; }
	
	$plurk_link = 'http://www.plurk.com/?qualifier=shares&amp;status='.urlencode($share_link." (".$fb_title.") " . $share_img);
	$twitter_link = "javascript: void(window.open('http://twitter.com/home/?status='.concat(encodeURIComponent('".$fb_title."')) .concat(' ') .concat(encodeURIComponent('".$share_link."'))));";	

$user['policy'] = explode('|', $user['policy']);
$keyword_issues = implode(',', $user['policy']);
$keywords = '綠黨,挺好的,九合一,選舉,greenparty';

?>		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<!--[if IE]><meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"><![endif]-->
		<meta content="width=device-width, initial-scale=1, maximum-scale=1" name="viewport">
		<meta content="black" name="apple-mobile-web-app-status-bar-style">

		<title><?php echo $html_title?></title>
		<meta name="keywords" content="<?php echo $user['title']?>,<?php echo $section_data['title']?>,<?php echo $keyword_issues?>,<?php echo $keywords?>" />
		<meta property="og:title" content="<?php echo $fb_title?>" />
		<meta property="og:type" content="article"/>
		<meta property="og:url" content="<?php echo $share_link?>" />
		<meta property="og:image" content="<?php echo $share_img?>" />
		<meta property="og:site_name" content="2014 挺好的！綠黨政治代理人" /> 
		<meta property="og:description" content="<?php echo $fb_description?>" />  
		<meta property="og:see_also" content="http://greenparty.org.tw/">
<?php if($videolink) { ?>
		<meta property="og:video" content="<?php echo $videolink?>" />
		<meta property="og:video:secure_url" content="<?php echo $videolink_ssl?>" />
		<meta property="og:video:width" content="568" />
		<meta property="og:video:height" content="320" />
		<meta property="og:video:type" content="application/x-shockwave-flash" />		<?php } ?>
		<meta property="fb:app_id" content="687618544645054" />
		<meta property="fb:admins" content="100000125299492" />
		<meta property="og:locale" content="zh_TW" />
		<link rel="shortcut icon" href="/favicon.ico"/>
		<meta content="#191d24" name="msapplication-TileColor">
		<meta content="<?php echo $user['logo'];?>" name="msapplication-TileImage">
		<link href="<?php echo $user['logo'];?>" rel="apple-touch-icon-precomposed">
		<script>
			function fb() {window.open('<?php echo "http://www.facebook.com/sharer.php?u=".urlencode($share_link)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
			function pl() {window.open('<?php echo $plurk_link?>');}
			function fb_index() {window.open('<?php echo "http://www.facebook.com/sharer.php?u=".urlencode(WEB)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
		</script>

<!--GA-->
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-54051080-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    //ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
	ga.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'stats.g.doubleclick.net/dc.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>  
<!--GA-->  
