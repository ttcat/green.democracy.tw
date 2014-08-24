<?
$display_header = Array(

		'bio'=> array('title' => '簡介','desc' => '', 'menu' => '1'),
		'issues'=> array('title' => '政見','desc' => '', 'menu' => '2'),
		'endorsements'=> array('title' => '各界推薦','desc' => '', 'menu' => '3'),
		'events'=> array('title' => '活動行程','desc' => '', 'menu' => '4'),		
		'pledge'=> array('title' => '政治代理人公約','desc' => '', 'menu' => '5'),		
		'finance'=> array('title' => '捐款徵信','desc' => '', 'menu' => '4'),	
		
);

$section_data = $display_header[$section];
$this_url = WEB.'/'.$current_url;

if($nid && $object) { 
	foreach ($object as $key => $v) {

		if($section == 'index') { $v['node'] = $v; }
	
		if($v['node']['nid'] == $nid) {
				$nid_name = $v['node']['title'];
				$nid_desc = SL(strip_tags($v['node']['content']), 150);
				$fb_title =$nid_name .' - '. $user['title']  . '的' .$section_data['title'].' | 2014 挺好的！綠黨政治代理人';
				if($v['node']['photo']) { $share_img = $v['node']['photo']; }else{ $share_img = ""; }
				if($v['node']['videolink']) { $videolink = $v['node']['videolink']; }
				$nid_found = 1;
		}
	}
}

if($nid) {
	if(!$nid_found) {   include_once('404.inc');  exit(); }
}

function showFBlike_l($p){
	$url = WEB.$p;
	$fb='<div class="fb-like" data-href="'.$url.'" data-layout="button_count"  data-send="false" data-width="80" data-show-faces="false" data-font="verdana"></div>';
	return $fb;
}


if($section == 'index' && !$nid) { //index

	$fb_title = $user['title'] .' | 2014 挺好的！綠黨政治代理人';
	$html_title = $fb_title;
	$share_img = $user['logo'];
	$fb_description = $user['bio'];
 
}else{	// 沒有帶 nid 的一般單元

	if(!$fb_title) { $user['title'].'的'.$fb_title = $section_data['title'].' | 2014 挺好的！綠黨政治代理人'; }
	if(!$share_img) { $share_img = ""; }
	$html_title = $fb_title;
	if(!$fb_description) $fb_description = $nid_desc;
	
}

if(!$share_link) {	$share_link = $this_url; }
if(!$html_title) {	$html_title = $fb_title; }
if($share_img == '') { $share_img = $user['icon']; }
if(!isset($fb_description) or $fb_description == '') {	$fb_description = '2014 挺好的人選、挺好的政黨、挺好的！台灣綠黨政治代理人官方網站。'; }
	
	$plurk_link = 'http://www.plurk.com/?qualifier=shares&amp;status='.urlencode($share_link." (".$fb_title.") " . $share_img);
	$twitter_link = "javascript: void(window.open('http://twitter.com/home/?status='.concat(encodeURIComponent('".$fb_title."')) .concat(' ') .concat(encodeURIComponent('".$share_link."'))));";	
	

?>		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<!--[if IE]><meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"><![endif]-->
		<meta content="width=device-width, initial-scale=1, maximum-scale=1" name="viewport">
		<meta content="black" name="apple-mobile-web-app-status-bar-style">

		<title><?=$html_title?></title>
		<meta name="keywords" content="綠黨,<?=$user['title']?>,<?=$section_data['title']?>,<?=$keywords?>" />
		<meta property="og:title" content="<?=$fb_title?>" />
		<meta property="og:type" content="article"/>
		<meta property="og:url" content="<?=$share_link?>" />
		<meta property="og:image" content="<?=$share_img?>" />
		<meta property="og:site_name" content="2014 挺好的！綠黨政治代理人" /> 
		<meta property="og:description" content="<?=$fb_description?>" />  
<? if($videolink) { ?>
		<meta property="og:video" content="<?=$videolink?>" />
		<meta property="og:video:width" content="568" />
		<meta property="og:video:height" content="320" />
		<meta property="og:video:type" content="application/x-shockwave-flash" />		<? } ?>
		<meta content="" name="msapplication-TileColor">
		<meta content="IE10" name="msapplication-TileImage">
		<meta property="fb:app_id" content="687618544645054" />
		<meta property="fb:admins" content="100000125299492" />
		<meta property="og:locale" content="zh_TW" />    	
		<link rel="shortcut icon" href="images/favicon.ico"/>
		<link href="" rel="apple-touch-icon-precomposed">
		<script>
			function fb() {window.open('<?="http://www.facebook.com/sharer.php?u=".urlencode($share_link)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
			function pl() {window.open('<?=$plurk_link?>');}
			function fb_index() {window.open('<?="http://www.facebook.com/sharer.php?u=".urlencode(WEB)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
		</script>