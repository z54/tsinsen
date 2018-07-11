var svst;
var cs;
function two(x){return (x>=10?"":"0")+x;}
function o(x){return document.getElementById(x);}
function ontime()
{
	var svnow=svst+Math.floor((new Date().getTime()-cs)/1000);
	o('ctime').innerHTML=two(Math.floor(svnow/3600)%24)+":"+two(Math.floor(svnow/60)%60)+":"+two(svnow%60);
}
function startTi(stime, ctime)
{
	svst = stime;cs = ctime;
	ontime();setInterval(ontime, 1000);
}
function delConfirm(){return confirm("删除后将不可恢复，你确定要删除此项吗？");}

//var menuO;
function loginClick(){workLogin(e("username").value,e("password").value);}
function pwdkey(e){ e = e || window.event; if(e && e.keyCode==13)loginClick();}
function logoutClick(){workLogout();}
function emailClick(){workEmail(e("email").value);}
function regClick() {window.location.href="/userregister.page";}
function renrenlogin() {
	window.location.href="https://graph.renren.com/oauth/authorize?client_id=177766&response_type=code&redirect_uri=http%3A%2F%2Fwww.tsinsen.com%2FRenrenLogin.do&display=page";
}
function weibologin() {
	window.location.href="https://api.weibo.com/2/oauth2/authorize?client_id=1707773381&redirect_uri=http%3A%2F%2Fwww.tsinsen.com%2FWeiboLogin.do&response_type=code";
}
function qqlogin() {
	window.location.href="https://graph.qq.com/oauth2.0/authorize?response_type=code&client_id=100243191&redirect_uri=http%3A%2F%2Fwww.tsinsen.com%2FQQLogin.do";
}
function checkUInfo(uinfo)
{
	if (e("mainm"))
	{
		checkV(e("mainm"),uinfo);
		e("mainm").style.display = "block";
	}
	var ts = parseInt(uinfo["times"]), tc = parseInt(uinfo["timec"]);
	if (!isNaN(ts) && !isNaN(tc))
		startTi(ts, tc);
	if (uinfo.isUser)
	{
		var ust = " &gt;&gt; 当前用户：<b>" + uinfo["login"] + "(" + uinfo["name"] + ")</b> <a href='###' onclick='logoutClick()'>登出</a> &nbsp; 当前所在课程：<b>" + uinfo["course"] + "</b> <a href='/DomainChange.page'>课程切换</a>";
		if (!isset(uinfo.isAdmin) || !uinfo.isAdmin)
			ust += " &nbsp; 我的角色：<b>普通用户</b>";
		else
		{
			ust += " &nbsp; 我的角色：<b>课程管理员</b>";
			if (uinfo["coursetype"] == "0")
				ust += " &nbsp; <span style='color:red;'>课程还未审核通过，不能添加用户</span>";
		}
		if (uinfo["msgs"] && parseInt(uinfo["msgs"])>0)
		{
			ust += ' &nbsp; <a href="/MyMessages.page" style="color:#D44; font-weight:bold; background-color:#8F8">您有' + uinfo["msgs"] + '条未读消息</a>';
		}
		ust += ' &nbsp; 将本站分享到：<div class="inl vmid show"><a class="share_renren" title="分享到人人网" onclick="renrenShareSiteClick()"></a> &nbsp; <a class="share_qq" title="分享到QQ空间" onclick="qqShareSiteClick()"></a> &nbsp; <a class="share_weibo" title="分享到新浪微博" onclick="weiboShareSiteClick()"></a></div>';
		e("cuinfo").innerHTML = ust;
	}
}
function doSearch(query)
{
	if(!query) query = "";
	location = "/ProblemArchive.page?keyword=" + query;
}

function onPageStart()
{
	checkUInfo(getUserInfo());
	createSearchBox(e("topOp"), "试题名称、描述", doSearch);
}

function getSiteDesc()
{
	return "清橙网络自动评测系统用于C/C++/Pascal/Java程序设计基础、算法、数据结构等课程的教学，以及中学信息学奥林匹克竞赛、大学ACM/ICPC程序设计竞赛的管理网站。本站已多次应用于清华大学、中国人民大学等学校的课程教学以及清华大学研究生入学考试、两岸清华、清华大学信息学夏令营的评测，并用于信息学奥林匹克中国国家队的训练中。";
}

function weiboShareSiteClick() {
	var _w = 16 , _h = 16;
	var param = {
		url:"http://www.tsinsen.com/",
		type:'3',
		count:'', /**是否显示分享数，1显示(可选)*/
		appkey:'1707773381', /**您申请的应用appkey,显示分享来源(可选)*/
		title:"清橙网络自动评测系统", /**分享的文字内容(可选，默认为所在页面的title)*/
		pic:'http://www.tsinsen.com/images/tsinsen100.png', /**分享图片的路径(可选)*/
		ralateUid:'', /**关联用户的UID，分享微博会@该用户(可选)*/
		language:'zh_cn', /**设置语言，zh_cn|zh_tw(可选)*/
		rnd:new Date().valueOf()
	}
	rrShareOnclick(param, "http://service.weibo.com/share/share.php");
}

function qqShareSiteClick() {
	var param = {
		url:"http://www.tsinsen.com/",
		showcount:'0',/*是否显示分享总数,显示：'1'，不显示：'0' */
		desc:'',/*默认分享理由(可选)*/
		summary:getSiteDesc(),/*分享摘要(可选)*/
		title:'清橙网络自动评测系统',/*分享标题(可选)*/
		site:'清橙网络自动评测系统',/*分享来源 如：腾讯网(可选)*/
		pics:'http://www.tsinsen.com/images/tsinsen100.png', /*分享图片的路径(可选)*/
		style:'203',
		width:22,
		height:22
	};
	rrShareOnclick(param, "http://sns.qzone.qq.com/cgi-bin/qzshare/cgi_qzshare_onekey");
}

function renrenShareSiteClick() {
	var param = {
		resourceUrl : 'http://www.tsinsen.com/',	//分享的资源Url
		pic : 'http://www.tsinsen.com/images/tsinsen100.png',		//分享的主题图片Url
		title : "清橙网络自动评测系统",		//分享的标题
		description : getSiteDesc()	//分享的详细描述
	};
	rrShareOnclick(param);
}


var Renren = Renren || {};
if(!Renren.share){
Renren.share = function() {
    var isIE = navigator.userAgent.match(/(msie) ([\w.]+)/i);
    var hl = location.href.indexOf('#');
    var resUrl = (hl == -1 ? location.href : location.href.substr(0, hl));
    var shareImgs = "";
	var sl = function(str) {
		var placeholder = new Array(23).join('x');
		str = str
				.replace(
						/(https?|ftp|gopher|telnet|prospero|wais|nntp){1}:\/\/\w*[\u4E00-\u9FA5]*((?![\"| |\t|\r|\n]).)+/ig,
						function(match) {
							return placeholder + match.substr(171);
						}).replace(/[^\u0000-\u00ff]/g, "xx");
		return Math.ceil(str.length / 2);
	};
	var cssImport = function(){
	    var static_url = 'http://xnimg.cn/xnapp/share/css/v2/rrshare.css';
		var b = document.createElement("link");
        b.rel = "stylesheet";
        b.type = "text/css";
        b.href = static_url;
        (document.getElementsByTagName("head")[0] || document.body).appendChild(b)
	};
    var getShareType = function (dom) {
        return dom.getAttribute("type") || "button"
    };
    var opts = {};
    if(typeof(imgMinWidth)!='undefined'){
    	opts.imgMinWidth = imgMinWidth || 60;
    } else {
    	opts.imgMinWidth = 60;
    }
    if(typeof(imgMinHeight)!='undefined'){
    	opts.imgMinHeight = imgMinHeight || 60;
    } else {
    	opts.imgMinHeight = 60;
    }
	var renderShareButton = function (btn,index) {
		if(btn.rendered){
			return;
		}
		btn.paramIndex = index;
        var shareType = getShareType(btn).split("_");
        var showType = shareType[0] == "icon" ? "icon" : "button";
        var size = shareType[1] || "small";
        var shs = "xn_share_"+showType+"_"+size;
        var innerHtml = [
                         '<span class="xn_share_wrapper ',shs,'"></span>'
                         ];
	    btn.innerHTML = innerHtml.join("");
	    btn.rendered = true;
	};
	var postTarget = function(opts) {
		var form = document.createElement('form');
		form.action = opts.url;
		form.target = opts.target;
		form.method = 'POST';
		form.acceptCharset = "UTF-8";
		for (var key in opts.params) {
			var val = opts.params[key];
			if (val !== null && val !== undefined) {
				var input = document.createElement('textarea');
				input.name = key;
				input.value = val;
				form.appendChild(input);
			}
		}
		var hidR = document.getElementById('renren-root-hidden');
		if (!hidR) {
			hidR = document.createElement('div'), syl = hidR.style;
			syl.positon = 'absolute';
			syl.top = '-10000px';
			syl.width = syl.height = '0px';
			hidR.id = 'renren-root-hidden';
			(document.body || document.getElementsByTagName('body')[0])
					.appendChild(hidR);
		}
		hidR.appendChild(form);
		try {
			var cst = null;
			if (isIE && document.charset.toUpperCase() != 'UTF-8') {
				cst = document.charset;
				document.charset = 'UTF-8';
			}
			form.submit();
		} finally {
			form.parentNode.removeChild(form);
			if (cst) {
				document.charset = cst;
			}
		}
	};
	var getCharSet = function(){
		if(document.charset){
			return document.charset.toUpperCase();
		} else {
			var metas = document.getElementsByTagName("meta");
			for(var i=0;i < metas.length;i++){
				var meta = metas[i];
				var metaCharset = meta.getAttribute('charset');
				if(metaCharset){
					return meta.getAttribute('charset');
				}
				var metaContent = meta.getAttribute('content');
				if(metaContent){
					var contenxt = metaContent.toLowerCase();
					var begin = contenxt.indexOf("charset=");
					if(begin!=-1){
						var end = contenxt.indexOf(";",begin+"charset=".length);
						if(end != -1){
							return contenxt.substring(begin+"charset=".length,end);
						}
						return contenxt.substring(begin+"charset=".length);
					}
				}
			}
		}
		return '';
	}
	var charset = getCharSet();
    var getParam = function (param){
    	param = param || {};
		param.api_key = param.api_key || '';
    	param.resourceUrl = param.resourceUrl || resUrl;
    	param.title = param.title || '';
    	param.pic = param.pic || '';
    	param.description = param.description || ''; 
    	if(resUrl == param.resourceUrl){
    		param.images = param.images || shareImgs;//一般就是当前页面的分享,因此取当前页面的img
    	}
    	param.charset = param.charset || charset || '';
    	return param;
    }
	var onclick = function(data, submitUrl) {
		if (!submitUrl)
			submitUrl = 'http://widget.renren.com/dialog/share';
		var p = getParam(data);
		var prm = [];
		for (var i in p) {
			if (p[i])
				prm.push(i + '=' + encodeURIComponent(p[i]));
		}
		var url = submitUrl+"?" + prm.join('&'), maxLgh = (isIE
				? 2048
				: 4100), wa = 'width=700,height=650,left=0,top=0,resizable=yes,scrollbars=1';
		if (url.length > maxLgh) {
			window.open('about:blank', 'fwd', wa);
			postTarget({
				url : submitUrl,
				target : 'fwd',
				params : p
			});
		} else {
			window.open(url, 'fwd', wa);
		}
		return false;
	};
	window["rrShareOnclick"] = onclick;
	var init = function() {
		if (Renren.share.isReady || document.readyState !== 'complete')
			return;
		var imgs = document.getElementsByTagName('img'), imga = [];
		for (var i = 0; i < imgs.length; i++) {
			if (imgs[i].width >= opts.imgMinWidth
					&& imgs[i].height >= opts.imgMinHeight) {
				imga.push(imgs[i].src);
			}
		}
		window["rrShareImgs"] = imga;
		if (imga.length > 0)
			shareImgs = imga.join('|');
		if (document.addEventListener) {
			document.removeEventListener('DOMContentLoaded', init, false);
		} else {
			document.detachEvent('onreadystatechange', init);
		}
		//cssImport();
		var shareBtn = document.getElementsByName("xn_share");
		var len = shareBtn?shareBtn.length:0;
        for (var b = 0; b < len; b++) {
            var a = shareBtn[b];
            renderShareButton(a,b);
        }
		Renren.share.isReady = true;
	};
	if (document.readyState === 'complete') {
		init();
	} else if (document.addEventListener) {
		document.addEventListener('DOMContentLoaded', init, false);
		window.addEventListener('load', init, false);
	} else {
		document.attachEvent('onreadystatechange', init);
		window.attachEvent('onload', init);
	}
};
Renren.share();
}

