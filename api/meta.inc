<?

$display_header = Array(

		'endorsements'=> array('title' => '各界推薦2','desc' => '', 'menu' => '3'),

	);

$section_data = $display_header[$section];
$this_url = WEB.'/'.$current_url;

function headersend() {
	$mypage = $section;
	$pageNotSend =  array('joinspot_done.php','board_analysis.php','top10_film.php','top10_news.php','top10_actor.php');
	for($i=0; $i < count($pageNotSend); $i++) {
		if($mypage == $pageNotSend[$i]) {
			return false;
		}
	}
	return true;
}

function showFBlike_l($p){
	$url = WEB.$p;
	$fb='<div class="fb-like" data-href="'.$url.'" data-layout="button_count"  data-send="false" data-width="80" data-show-faces="false" data-font="verdana"></div>';
	return $fb;
}


if($section == 'newsCT' or $section == 'board_analysis'){

	$fb_title = $news_title.' | 2014 挺好的！綠黨政治代理人';
	$html_title = $fb_title;
	// $share_img = get_UPIMG_no($article_staus['post_pic'],'','');
	$t = date("Ymdh");
	$share_img = ($news_pic) ? "$Host/upload/$news_pic".'?'.$t : "$HttpHost/images/newsListPic.jpg".'?'.$t;
	$share_link = $this_url.'?news_no='.$news_no;
	$fb_description = $news_desc;


}else if($section == 'index') {

	$fb_title = $user['title'] .' | 2014 挺好的！綠黨政治代理人';
	$html_title = $fb_title;
	$share_img = $user['logo'];
	$fb_description = $user['bio'];
	

}else if($section == 's') {

	$html_title = $fb_title;
	$fb_description = $nid_desc;
	$share_link = $this_url;
 
}else{	// 沒有帶 nid 的一般單元

	if(!$fb_title) { $fb_title = $section_data['title'].' - '.$user['title'].' | 2014 挺好的！綠黨政治代理人'; }
	if(!$share_img) { $share_img = ""; }
	
	$html_title = $fb_title;
	$fb_description = $nid_desc;
	$share_link = $this_url;
}


if(!$share_link) {	$share_link = $this_url; }
if(!$html_title) {	$html_title = $fb_title; }
if($share_img == '') { $share_img = $user['icon']; }
if(!isset($fb_description) or $fb_description == '') {	$fb_description = '2014 挺好的人選、挺好的政黨、挺好的！台灣綠黨政治代理人官方網站。'; }
	
	$plurk_link = 'http://www.plurk.com/?qualifier=shares&amp;status='.urlencode($share_link." (".$fb_title.") " . $share_img);
	$twitter_link = "javascript: void(window.open('http://twitter.com/home/?status='.concat(encodeURIComponent('".$fb_title."')) .concat(' ') .concat(encodeURIComponent('".$share_link."'))));";	
	

?>		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<!--[if IE]><meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"><![endif]-->
		<meta content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no" name="viewport">
		<meta content="black" name="apple-mobile-web-app-status-bar-style">

		<title><?=$html_title?></title>
		<meta name="keywords" content="綠黨,<?=$user['title']?>,<?=$keywords?>" />
		<meta property="og:title" content="<?=$fb_title?>" />
		<meta property="og:type" content="article"/>
		<meta property="og:url" content="<?=$share_link?>" />
		<meta property="og:image" content="<?=$share_img?>" />
		<meta property="og:site_name" content="2014 挺好的！綠黨政治代理人" /> 
		<meta property="og:description" content="<?=$fb_description?>" />  

		<link rel="shortcut icon" href="images/favicon.ico"/>
		<script>
			function fb() {window.open('<?="http://www.facebook.com/sharer.php?u=".urlencode($share_link)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
			function pl() {window.open('<?=$plurk_link?>');}
			function fb_index() {window.open('<?="http://www.facebook.com/sharer.php?u=".urlencode(WEB)?>', 'Facebook','toolbar=0,status=0,width=626,height=436');}
		</script>
		