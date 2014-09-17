<?php
date_default_timezone_set("Asia/Taipei");
global $u;

require_once 'api/Mobile_Detect.inc';
$detect = new Mobile_Detect;
define('WEB', 'http://green.democracy.tw');

global $f;
global $key;
global $value;


if($u && $found) {

	//個人資料
	$string = http_request_contents("http://v.democracy.tw/{$u}/site.json", 60*60);
	if($string) { 
	  $user = json_decode($string,true);
	  $user = $user['nodes'][0]['node'];
	}

	//推薦
	$string = http_request_contents("http://v.democracy.tw/{$u}/timeline.json/person");
	$recommendation = json_decode($string,true);
	$recommendation = $recommendation['nodes'];
	$endorsment = $recommendation;
	shuffle($recommendation);

	//news
	$string = http_request_contents("http://v.democracy.tw/{$u}/timeline.json/news");
	$news = json_decode($string,true);
	$news = $news['nodes'];
	shuffle($news);

}

//function

function SL($str,$len,$name=null){

	if(!preg_match("[/^\x80-\xff]","$str")) {
		$len = $len;
	}else{
		$len = $len +2;
	}

	mb_internal_encoding("UTF-8");
	$str = str_replace('<br>','',$str);
	if( mb_strlen($str) > $len){ $dot='...';} else { $dot=''; }
	
	if($name == 1) { $dot = ''; }

	return mb_substr($str,0,$len).$dot;

}


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


function filter_xss($string, $allowed_tags = array('a', 'em', 'strong', 'cite', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd')) {
  // Only operate on valid UTF-8 strings. This is necessary to prevent cross
  // site scripting issues on Internet Explorer 6.
  if (!drupal_validate_utf8($string)) {
    return '';
  }
  // Store the input format
  _filter_xss_split($allowed_tags, TRUE);
  // Remove NUL characters (ignored by some browsers)
  $string = str_replace(chr(0), '', $string);
  // Remove Netscape 4 JS entities
  $string = preg_replace('%&\s*\{[^}]*(\}\s*;?|$)%', '', $string);

  // Defuse all HTML entities
  $string = str_replace('&', '&amp;', $string);
  // Change back only well-formed entities in our whitelist
  // Decimal numeric entities
  $string = preg_replace('/&amp;#([0-9]+;)/', '&#\1', $string);
  // Hexadecimal numeric entities
  $string = preg_replace('/&amp;#[Xx]0*((?:[0-9A-Fa-f]{2})+;)/', '&#x\1', $string);
  // Named entities
  $string = preg_replace('/&amp;([A-Za-z][A-Za-z0-9]*;)/', '&\1', $string);

  return preg_replace_callback('%
    (
    <(?=[^a-zA-Z!/])  # a lone <
    |                 # or
    <!--.*?-->        # a comment
    |                 # or
    <[^>]*(>|$)       # a string that starts with a <, up until the > or the end of the string
    |                 # or
    >                 # just a >
    )%x', '_filter_xss_split', $string);
}


function drupal_validate_utf8($text) {
  if (strlen($text) == 0) {
    return TRUE;
  }
  // For performance reasons this logic is duplicated in check_plain().
  return (preg_match('/^./us', $text) == 1);
}


function _filter_xss_split($m, $store = FALSE) {
  static $allowed_html;

  if ($store) {
    $allowed_html = array_flip($m);
    return;
  }

  $string = $m[1];

  if (substr($string, 0, 1) != '<') {
    // We matched a lone ">" character
    return '&gt;';
  }
  else if (strlen($string) == 1) {
    // We matched a lone "<" character
    return '&lt;';
  }

  if (!preg_match('%^(?:<\s*(/\s*)?([a-zA-Z0-9]+)([^>]*)>?|(<!--.*?-->))$%', $string, $matches)) {
    // Seriously malformed
    return '';
  }

  $slash = trim($matches[1]);
  $elem = &$matches[2];
  $attrlist = &$matches[3];
  $comment = &$matches[4];

  if ($comment) {
    $elem = '!--';
  }

  if (!isset($allowed_html[strtolower($elem)])) {
    // Disallowed HTML element
    return '';
  }

  if ($comment) {
    return $comment;
  }

  if ($slash != '') {
    return "</$elem>";
  }

  // Is there a closing XHTML slash at the end of the attributes?
  // In PHP 5.1.0+ we could count the changes, currently we need a separate match
  $xhtml_slash = preg_match('%\s?/\s*$%', $attrlist) ? ' /' : '';
  $attrlist = preg_replace('%(\s?)/\s*$%', '\1', $attrlist);

  // Clean up attributes
  $attr2 = implode(' ', _filter_xss_attributes($attrlist));
  $attr2 = preg_replace('/[<>]/', '', $attr2);
  $attr2 = strlen($attr2) ? ' ' . $attr2 : '';

  return "<$elem$attr2$xhtml_slash>";
}


function _filter_xss_attributes($attr) {
  $attrarr = array();
  $mode = 0;
  $attrname = '';

  while (strlen($attr) != 0) {
    // Was the last operation successful?
    $working = 0;

    switch ($mode) {
      case 0:
        // Attribute name, href for instance
        if (preg_match('/^([-a-zA-Z]+)/', $attr, $match)) {
          $attrname = strtolower($match[1]);
          $skip = ($attrname == 'style' || substr($attrname, 0, 2) == 'on');
          $working = $mode = 1;
          $attr = preg_replace('/^[-a-zA-Z]+/', '', $attr);
        }

        break;

      case 1:
        // Equals sign or valueless ("selected")
        if (preg_match('/^\s*=\s*/', $attr)) {
          $working = 1;
          $mode = 2;
          $attr = preg_replace('/^\s*=\s*/', '', $attr);
          break;
        }

        if (preg_match('/^\s+/', $attr)) {
          $working = 1;
          $mode = 0;
          if (!$skip) {
            $attrarr[] = $attrname;
          }
          $attr = preg_replace('/^\s+/', '', $attr);
        }

        break;

      case 2:
        // Attribute value, a URL after href= for instance
        if (preg_match('/^"([^"]*)"(\s+|$)/', $attr, $match)) {
          $thisval = filter_xss_bad_protocol($match[1]);

          if (!$skip) {
            $attrarr[] = "$attrname=\"$thisval\"";
          }
          $working = 1;
          $mode = 0;
          $attr = preg_replace('/^"[^"]*"(\s+|$)/', '', $attr);
          break;
        }

        if (preg_match("/^'([^']*)'(\s+|$)/", $attr, $match)) {
          $thisval = filter_xss_bad_protocol($match[1]);

          if (!$skip) {
            $attrarr[] = "$attrname='$thisval'";
          }
          $working = 1;
          $mode = 0;
          $attr = preg_replace("/^'[^']*'(\s+|$)/", '', $attr);
          break;
        }

        if (preg_match("%^([^\s\"']+)(\s+|$)%", $attr, $match)) {
          $thisval = filter_xss_bad_protocol($match[1]);

          if (!$skip) {
            $attrarr[] = "$attrname=\"$thisval\"";
          }
          $working = 1;
          $mode = 0;
          $attr = preg_replace("%^[^\s\"']+(\s+|$)%", '', $attr);
        }

        break;
    }

    if ($working == 0) {
      // not well formed, remove and try again
      $attr = preg_replace('/
        ^
        (
        "[^"]*("|$)     # - a string that starts with a double quote, up until the next double quote or the end of the string
        |               # or
        \'[^\']*(\'|$)| # - a string that starts with a quote, up until the next quote or the end of the string
        |               # or
        \S              # - a non-whitespace character
        )*              # any number of the above three
        \s*             # any number of whitespaces
        /x', '', $attr);
      $mode = 0;
    }
  }

  // the attribute list ends with a valueless attribute like "selected"
  if ($mode == 1) {
    $attrarr[] = $attrname;
  }
  return $attrarr;
}

function filter_xss_bad_protocol($string, $decode = TRUE) {
  static $allowed_protocols;
  if (!isset($allowed_protocols)) {
    $allowed_protocols = array_flip(variable_get('filter_allowed_protocols', array('http', 'https', 'ftp', 'news', 'nntp', 'tel', 'telnet', 'mailto', 'irc', 'ssh', 'sftp', 'webcal', 'rtsp')));
  }

  // Get the plain text representation of the attribute value (i.e. its meaning).
  if ($decode) {
    $string = decode_entities($string);
  }

  // Iteratively remove any invalid protocol found.

  do {
    $before = $string;
    $colonpos = strpos($string, ':');
    if ($colonpos > 0) {
      // We found a colon, possibly a protocol. Verify.
      $protocol = substr($string, 0, $colonpos);
      // If a colon is preceded by a slash, question mark or hash, it cannot
      // possibly be part of the URL scheme. This must be a relative URL,
      // which inherits the (safe) protocol of the base document.
      if (preg_match('![/?#]!', $protocol)) {
        break;
      }
      // Per RFC2616, section 3.2.3 (URI Comparison) scheme comparison must be case-insensitive
      // Check if this is a disallowed protocol.
      if (!isset($allowed_protocols[strtolower($protocol)])) {
        $string = substr($string, $colonpos + 1);
      }
    }
  } while ($before != $string);
  return check_plain($string);
}

function variable_get($name, $default) {
  global $conf;

  return isset($conf[$name]) ? $conf[$name] : $default;
}


function decode_entities($text, $exclude = array()) {
  static $html_entities;
  if (!isset($html_entities)) {
    include_once 'api/unicode.entities.inc';
  }

  // Flip the exclude list so that we can do quick lookups later.
  $exclude = array_flip($exclude);

  // Use a regexp to select all entities in one pass, to avoid decoding 
  // double-escaped entities twice. The PREG_REPLACE_EVAL modifier 'e' is
  // being used to allow for a callback (see 
  // http://php.net/manual/en/reference.pcre.pattern.modifiers).
  return preg_replace('/&(#x?)?([A-Za-z0-9]+);/e', '_decode_entities("$1", "$2", "$0", $html_entities, $exclude)', $text);
}

function check_plain($text) {
  return htmlspecialchars($text, ENT_QUOTES, 'UTF-8');
}

function http_request_contents($url, $expire = 900){
  $now = time();
  $cache_id = md5($url);
  $dir = 'cache';
  $filename = $dir.'/'.$cache_id.'.cache';
  $cached = file_exists($filename);

  // expired
  if(!$cached || ($now - filemtime($filename) > $expire)){
    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    $data = curl_exec($ch);
    $status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    curl_close($ch);
    if($status == 200){
      file_put_contents($filename, $data);
      return $data;
    }
  }

  // else from cache
  if($cached){
    return file_get_contents($filename);
  }

  // else error
  return '';
}


function _decode_entities($prefix, $codepoint, $original, &$html_entities, &$exclude) {
  // Named entity
  if (!$prefix) {
    // A named entity not in the exclude list.
    if (isset($html_entities[$original]) && !isset($exclude[$html_entities[$original]])) {
      return $html_entities[$original];
    }
    else {
      return $original;
    }
  }
  // Hexadecimal numerical entity
  if ($prefix == '#x') {
    $codepoint = base_convert($codepoint, 16, 10);
  }
  // Decimal numerical entity (strip leading zeros to avoid PHP octal notation)
  else {
    $codepoint = preg_replace('/^0+/', '', $codepoint);
  }
  // Encode codepoint as UTF-8 bytes
  if ($codepoint < 0x80) {
    $str = chr($codepoint);
  }
  else if ($codepoint < 0x800) {
    $str = chr(0xC0 | ($codepoint >> 6)) . chr(0x80 | ($codepoint & 0x3F));
  }
  else if ($codepoint < 0x10000) {
    $str = chr(0xE0 | ($codepoint >> 12)) . chr(0x80 | (($codepoint >> 6) & 0x3F)) . chr(0x80 | ($codepoint & 0x3F));
  }
  else if ($codepoint < 0x200000) {
    $str = chr(0xF0 | ($codepoint >> 18)) . chr(0x80 | (($codepoint >> 12) & 0x3F)) . chr(0x80 | (($codepoint >> 6) & 0x3F)) . chr(0x80 | ($codepoint & 0x3F));
  }
  // Check for excluded characters
  if (isset($exclude[$str])) {
    return $original;
  }
  else {
    return $str;
  }
}