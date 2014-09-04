<?php

function metavideo($url, $ssl) {

	$data = parse_url($url);
	$query = explode('&', $data['query']);
	
	//print_r($data);
	
	
	if($data['host'] == 'www.youtube.com' || $data['host'] == 'youtube.com' || $data['host'] == 'youtu.be') 
	{
		foreach($query as $q) 
	    { 
	    	//print_r($q);
    	    list($key, $value) = explode("=", $q); 
			if($key == 'v') { $video_id = $value; }
			if($ssl) { $url_new = 'https://www.youtube.com/v/'.$video_id; } else { $url_new = 'http://www.youtube.com/v/'.$video_id; }
			

	    } 	
    }
    
    
	return $url_new;
}

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

if($section == 'politician') { 
	$string_meta = file_get_contents("http://green.democracy.tw/{$u}/api/timeline?all");
	$object = json_decode($string_meta,true);
}

		
if($nid && $object) { 
	foreach ($object as $key => $v) {


		if($section == 'politician') { 
			
			if(!$v['section']) { //section = null = timeline_news_feed; otherwise go 404.
				$v['node'] = $v; 
				
				if($v['node']['nid'] == $nid) {
				
					$v_title = explode('</h3>',$v['node']['content']);
					$nid_name = strip_tags($v_title[0]);
					$nid_desc = SL(strip_tags($v_title[1]), 150);
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
					$fb_title =$nid_name .' - '. $user['title']  . '的' .$section_data['title'].' | 2014 挺好的！綠黨政治代理人';
					if($v['node']['photo']) { $share_img = $v['node']['photo']; }else{ $share_img = ""; }
					if($v['node']['videolink']) { $videolink = metavideo($v['node']['videolink'], 0); $videolink_ssl = metavideo($v['node']['videolink'], 1); }
					$nid_found = 1;
			}
		}
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
	$fb_description = $user['bio'];
 
}else if(!$nid) {	// 沒有帶 nid 的一般單元

	$fb_title = $user['title'].'的'.$section_data['title'].' | 2014 挺好的！綠黨政治代理人';
	if(!$share_img) { $share_img = ""; }
	$html_title = $fb_title;
	if(!$fb_description) $fb_description = '';
	
}



if(!$share_link) {	$share_link = $this_url; }
if(!$html_title) {	$html_title = $fb_title; }
if($share_img == '') { $share_img = $user['logo']; }

if(!isset($fb_description) or $fb_description == '') {	$fb_description = $user['title'].'－'.$user['section'].'：2014 挺好的人選、挺好的政黨、挺好的！台灣綠黨政治代理人官方網站。'; }
	
	$plurk_link = 'http://www.plurk.com/?qualifier=shares&amp;status='.urlencode($share_link." (".$fb_title.") " . $share_img);
	$twitter_link = "javascript: void(window.open('http://twitter.com/home/?status='.concat(encodeURIComponent('".$fb_title."')) .concat(' ') .concat(encodeURIComponent('".$share_link."'))));";	
	

$user['policy'] = explode('|', $user['policy']);			    		
$user['policyicon'] = explode('|', $user['policyicon']);

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
		<!-- <meta property="og:see_also" content=""> -->
<?php if($videolink) { ?>
		<meta property="og:video" content="<?php echo $videolink?>" />
		<meta property="og:video:secure_url" content="<?php echo $videolink_ssl?>" />
		<meta property="og:video:width" content="568" />
		<meta property="og:video:height" content="320" />
		<meta property="og:video:type" content="application/x-shockwave-flash" />		<?php } ?>
		<meta property="fb:app_id" content="687618544645054" />
		<meta property="fb:admins" content="100000125299492" />
		<meta property="og:locale" content="zh_TW" />
    <!--
		<meta content="" name="msapplication-TileColor">
		<meta content="IE10" name="msapplication-TileImage">
		<link rel="shortcut icon" href="images/favicon.ico"/>
		<link href="" rel="apple-touch-icon-precomposed">
    -->
		<script>
			function fb() {window.open('<?php echo "http://www.facebook.com/sharer.php?u=".urlencode($share_link)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
			function pl() {window.open('<?php echo $plurk_link?>');}
			function fb_index() {window.open('<?php echo "http://www.facebook.com/sharer.php?u=".urlencode(WEB)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
		</script>
