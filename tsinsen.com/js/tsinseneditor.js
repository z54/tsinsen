var __fckEditorInstance_ = new Array();

function FCKeditor_OnComplete( editorInstance )
{
	__fckEditorInstance_[editorInstance.Name] = editorInstance;
}

function getFckInst(idname)
{
	return __fckEditorInstance_[idname];
}

function createRichEditor(par, vname, val)
{
	var sBasePath = "/fckeditor/" ;
	var sSkin = 'office2003';
	
	var oFCKeditor = new FCKeditor( vname ) ;
	oFCKeditor.BasePath	= sBasePath ;
	
	var sSkinPath = sBasePath + 'editor/skins/' + sSkin + '/' ;
	oFCKeditor.Config['SkinPath'] = sSkinPath ;
	
	oFCKeditor.Config['PreloadImages'] =
		sSkinPath + 'images/toolbar.start.gif' + ';' +
		sSkinPath + 'images/toolbar.end.gif' + ';' +
		sSkinPath + 'images/toolbar.bg.gif' + ';' +
		sSkinPath + 'images/toolbar.buttonarrow.gif' ;
	oFCKeditor.ToolbarSet = "Jelly";
	oFCKeditor.Height	= 400 ;
	oFCKeditor.Value	= val;
	var _td = document.createElement("div");
	par.appendChild(_td);
	_td.innerHTML += oFCKeditor.CreateHtml();
	return oFCKeditor;
}

function createEditor(vname, val)
{
	var sBasePath = "/fckeditor/" ;
	var sSkin = 'office2003';
	
	var oFCKeditor = new FCKeditor( vname ) ;
	oFCKeditor.BasePath	= sBasePath ;
	
	var sSkinPath = sBasePath + 'editor/skins/' + sSkin + '/' ;
	oFCKeditor.Config['SkinPath'] = sSkinPath ;
	
	oFCKeditor.Config['PreloadImages'] =
		sSkinPath + 'images/toolbar.start.gif' + ';' +
		sSkinPath + 'images/toolbar.end.gif' + ';' +
		sSkinPath + 'images/toolbar.bg.gif' + ';' +
		sSkinPath + 'images/toolbar.buttonarrow.gif' ;
	
	oFCKeditor.ToolbarSet = "Jelly";
	
	oFCKeditor.Height	= 400 ;
	
	oFCKeditor.Value	= val;
	oFCKeditor.Create() ;
	return oFCKeditor;
}
