<?
$display_header = Array(

//		''=> array('title' => '','desc' => '2013 年 3 月 9 日的全國廢核大遊行，北中南東共有 22 萬人上街展現廢核的民間力量，要求直接停建核四，北部、中部、南 部、東部等數百個民間團體共同組成了「全國廢核行動平台」，進行大規模的民間力量串聯，希望能匯聚公民的力量一起行動。 替我們共同的未來一起努力！', 'catShare' => 'aboutus.php', 'menu' => '0'),
//		'joinspot'=> array('title' => '推廣：成為反核柑仔店','desc' => '不論你是擁有一間店面，或是擁有公開的空間，都可以在本網站登錄據點。經過審核後，您就可以成為反核柑仔店，並可以隨時修改據點資訊、更新活動、成為反核旗鋪貨點等。不只是透過網路，也請從你實體生活圈開始發揮影響力吧！', 'catShare' => 'joinspot.php', 'menu' => '0'),
//		'newsCT'=> array('title' => '', 'desc' => '', 'catShare' => 'news.php', 'menu' => '0'),
	);


define('WEB', 'http://green.democracy.tw/{$u}');

function curPageURL() {
	$pageURL = 'http';
 	if ($_SERVER["HTTPS"] == "on") {$pageURL .= "s";}
		$pageURL .= "://";
	 if ($_SERVER["SERVER_PORT"] != "80") {
		$pageURL .= $_SERVER["SERVER_NAME"].":".$_SERVER["SERVER_PORT"].$_SERVER["REQUEST_URI"];
	 } else {
		$pageURL .= $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"];
	 }
	 return $pageURL;
}

function curPageName($e=true) {
	
	$filename = substr($_SERVER["SCRIPT_NAME"],strrpos($_SERVER["SCRIPT_NAME"],"/")+1); 
	if($e) {
		return $filename;
	}else{
		return substr($filename,0,-4);
	}
}

echo curPageURL();

echo "<br>";

echo $_SERVER['REQUEST_URI'];

?>