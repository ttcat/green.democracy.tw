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
				
				<!-- add here-->
				<h2>2014 綠黨政治代理人公約</h2>
						<hr>

						<div>
							<p>

<h4>一、說明總論</h4>
為確保綠黨（以下稱本黨）提名的各級政治代理人，從參選到當選，均能實踐綠色政治的理念與原則，特訂定本公約。<br />
<br />
本黨所稱「政治代理人」，即一般所謂候選人或參選人，用以凸顯政治代理人係綠色政治理念傳遞之代表，因此應與委託人——綠色選民——有充分的溝通與互動，透過相互尊重的合作關係，將綠色政治理念帶入體制內實踐。<br />
<br />
本黨所稱綠色政治，係指推動公費選舉、公民參政、資訊公開、茁壯公民社會，及實踐且不違背全球綠色憲章之六大核心價值：生態智慧、社會正義、尊重多元、參與式民主、非暴力、不犧牲下一代資源的永續 。<br />
<br />
<h4>二、本黨與政治代理人對選民承諾</h4>
<ol>
	<li>競選期間，本黨應邀集符合綠色政治理念之政策顧問、公民團體，提出相關共同政見與發展方向。</li>
	<li>本黨與本黨提名之政治代理人，須共同遵守本黨的共同政見，並於當選之後，在社會監督、參議之下，以實際行動執行推動相關政策落實，體現政治「代理人」之真正精神，對選民負責。</li>
	<li>本黨與本黨提名之政治代理人，在競選期間內，無論正式或非正式，凡具有承諾性質之政見形式發表、言論、文宣與影像，都將受到本公約之約束：
		<ol class="olalpha">
			<li>政見必須符合綠色政治理念、全球綠人憲章之核心價值與願景方向。</li>
			<li>政見內容必須受到本黨與政治代理人邀集推薦之政策顧問、公民團體之監督或審議，不得在當選後任意修正內容、改變立場。</li>
		</ol>
	</li>
	<li>本黨應確保在競選期間乃至於政治代理人當選後問政、施政期間內，本公約條文各項內容、相關政見之約束力與效力。</li>
</ol>
<h4>三、本黨與政治代理人之協定</h4>
<ol>
	<li>本黨政治代理人在競選期間之經費運用，雙方應遵守以下原則：
		<ol class="olalpha">
			<li>本黨將盡可能協助政治代理人募得部分選舉經費，及相關政策、文宣、組織等選舉活動推展。</li>
			<li>政治代理人在競選期間所募得的政治獻金，應全數用於選舉支出，並有清楚的收支紀錄，於選舉結束後，交由本黨備查，並對外公開。</li>
			<li>無論有無當選，政治代理人在競選結束後若有剩餘經費（包含保證金之退還、選票補助款等所有款項），應按比例優先回捐本黨所代為募得之競選經費，最後剩餘經費及資產之使用由本黨與政治代理人議定之。</li>
		</ol>
	</li>
	<li>本黨提名之政治代理人若當選，公職的薪資與資源運用方式如下：
		<ol class="olalpha">
			<li>公職個人薪資應至少回捐三分之一，交由本黨統籌支用。薪資定義應區分競選各級不同公職，由中執委會另詳定之。</li>
			<li>公職資源方面，當選後所有助理的聘任，應由本黨與政治代理人共同邀請公民團體商議，共同議決任用人選，以落實本黨核心價值、候選人競選政見、兼顧黨務發展與選區組織工作。</li>
			<li>其他所有因公職所衍生之各種津貼、福利等，金錢與非金錢之資源，應公開來源與使用方式。</li>
		</ol>
	</li>
	<li>本黨提名之政治代理人在當選公職後，應遵守資訊公開與責信之原則，包括：
		<ol class="olalpha">
		<li>問政或施政紀錄需上網公開，並每月定期與選民、公民團體進行雙向溝通。</li>
		<li>擔任公職期間的收入與支出，除了個人薪資支出外，其餘應有清楚之收支紀錄，並於每年會計年度送交本黨備查，並對外公開徵信。</li>
		</ol>
	</li>
</ol>
<h4>四、政治誠信與責任</h4>
<ol>
	<li>簽署本公約且得到本黨提名推薦後，政治代理人如有在競選與擔任公職期間，違背本公約之情事，經查証屬實，政治代理人願接受最重開除黨籍之懲戒處分，並自願退還競選過程中本黨所提供所有資源之價格報酬。</li>
	<li>本公約條文之制定、修正與若有爭議之釐清等，將以本黨與該政治候選人之政治誠信為原則，由本黨中央執行委員會以合議制方式裁定，並受本黨中央評議委員會之監督。</li>
</ol>
    	                	</p><br/><br/>
    	                	
    	                	<div class="addthis_sharing_toolbox" data-url="http://green.democracy.tw/<?php print $u; ?>/bio ?>"></div>
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
