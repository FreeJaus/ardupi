<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="9008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="acher.vi" Type="VI" URL="../acher.vi"/>
		<Item Name="acher_icon.ico" Type="Document" URL="../../images/acher_icon.ico"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="Get String Text Bounds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Get String Text Bounds.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="Convert property node font to graphics font.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Convert property node font to graphics font.vi"/>
				<Item Name="Longest Line Length in Pixels.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Longest Line Length in Pixels.vi"/>
				<Item Name="Three Button Dialog CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog CORE.vi"/>
				<Item Name="Three Button Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog.vi"/>
				<Item Name="Merge Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Merge Errors.vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="acher_exe" Type="EXE">
				<Property Name="App_applicationGUID" Type="Str">{A7962AA2-AEE2-4D58-8091-1F8EC7480E0F}</Property>
				<Property Name="App_applicationName" Type="Str">acher.exe</Property>
				<Property Name="App_fileDescription" Type="Str">acher_exe</Property>
				<Property Name="App_fileVersion.major" Type="Int">1</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{C6FABCF7-732B-4773-9C3E-A8627D007C03}</Property>
				<Property Name="App_INI_GUID" Type="Str">{10072B60-DAEB-4A97-BEEA-0EAE95226632}</Property>
				<Property Name="App_internalName" Type="Str">acher_exe</Property>
				<Property Name="App_legalCopyright" Type="Str">GPL v3.0 @ Unai Martinez</Property>
				<Property Name="App_productName" Type="Str">acher_exe</Property>
				<Property Name="Bld_buildSpecName" Type="Str">acher_exe</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Destination[0].destName" Type="Str">acher.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../labview/builds/NI_AB_PROJECTNAME/acher_exe/acher.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../labview/builds/NI_AB_PROJECTNAME/acher_exe/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/acher_icon.ico</Property>
				<Property Name="Source[0].itemID" Type="Str">{A2134B0D-3965-4E24-8C51-89A42ABB0741}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/acher.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
			</Item>
			<Item Name="acher_inst" Type="Installer">
				<Property Name="arpCompany" Type="Str">.</Property>
				<Property Name="AutoIncrement" Type="Bool">true</Property>
				<Property Name="BldInfo.Count" Type="Int">1</Property>
				<Property Name="BldInfo[0].Dir" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="BldInfo[0].Tag" Type="Ref">/My Computer/Build Specifications/acher_exe</Property>
				<Property Name="BuildLabel" Type="Str">acher_inst</Property>
				<Property Name="BuildLocation" Type="Path">../builds/acher/acher_inst</Property>
				<Property Name="DirInfo.Count" Type="Int">1</Property>
				<Property Name="DirInfo.DefaultDir" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="DirInfo[0].DirName" Type="Str">acher</Property>
				<Property Name="DirInfo[0].DirTag" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="DirInfo[0].ParentTag" Type="Str">{3912416A-D2E5-411B-AFEE-B63654D690C0}</Property>
				<Property Name="DistID" Type="Str">{93C59B0D-3330-4414-86B6-42DEE6240C0D}</Property>
				<Property Name="DistParts.Count" Type="Int">2</Property>
				<Property Name="DistPartsInfo[0].FlavorID" Type="Str">DefaultFull</Property>
				<Property Name="DistPartsInfo[0].ProductID" Type="Str">{4E049CBB-01EE-4859-B4C8-26E42263CEE4}</Property>
				<Property Name="DistPartsInfo[0].ProductName" Type="Str">NI LabVIEW Run-Time Engine 2009</Property>
				<Property Name="DistPartsInfo[0].UpgradeCode" Type="Str">{1DA01FF3-1E36-4A14-802B-D195819E159B}</Property>
				<Property Name="DistPartsInfo[1].FlavorID" Type="Str">_deployment_</Property>
				<Property Name="DistPartsInfo[1].ProductID" Type="Str">{D6FC9FA9-3386-409A-8D62-EE026CA721D1}</Property>
				<Property Name="DistPartsInfo[1].ProductName" Type="Str">NI-VISA Runtime 4.5</Property>
				<Property Name="DistPartsInfo[1].UpgradeCode" Type="Str">{8627993A-3F66-483C-A562-0D3BA3F267B1}</Property>
				<Property Name="Executable" Type="Str">{A7962AA2-AEE2-4D58-8091-1F8EC7480E0F}</Property>
				<Property Name="ExeDir" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="FileInfo.Count" Type="Int">3</Property>
				<Property Name="FileInfo[0].DirTag" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="FileInfo[0].FileName" Type="Str">acher.exe</Property>
				<Property Name="FileInfo[0].FileTag" Type="Str">{A7962AA2-AEE2-4D58-8091-1F8EC7480E0F}</Property>
				<Property Name="FileInfo[0].Type" Type="Int">3</Property>
				<Property Name="FileInfo[0].TypeID" Type="Ref">/My Computer/Build Specifications/acher_exe</Property>
				<Property Name="FileInfo[1].DirTag" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="FileInfo[1].FileName" Type="Str">acher.aliases</Property>
				<Property Name="FileInfo[1].FileTag" Type="Str">{C6FABCF7-732B-4773-9C3E-A8627D007C03}</Property>
				<Property Name="FileInfo[1].Type" Type="Int">3</Property>
				<Property Name="FileInfo[1].TypeID" Type="Ref">/My Computer/Build Specifications/acher_exe</Property>
				<Property Name="FileInfo[2].DirTag" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="FileInfo[2].FileName" Type="Str">acher.ini</Property>
				<Property Name="FileInfo[2].FileTag" Type="Str">{10072B60-DAEB-4A97-BEEA-0EAE95226632}</Property>
				<Property Name="FileInfo[2].Type" Type="Int">3</Property>
				<Property Name="FileInfo[2].TypeID" Type="Ref">/My Computer/Build Specifications/acher_exe</Property>
				<Property Name="InstSpecVersion" Type="Str">9008022</Property>
				<Property Name="LicenseFile" Type="Ref"></Property>
				<Property Name="OSCheck" Type="Int">0</Property>
				<Property Name="OSCheck_Vista" Type="Bool">false</Property>
				<Property Name="ProductName" Type="Str">Acher</Property>
				<Property Name="ProductVersion" Type="Str">1.0.2</Property>
				<Property Name="ReadmeFile" Type="Ref"></Property>
				<Property Name="ShortcutInfo.Count" Type="Int">1</Property>
				<Property Name="ShortcutInfo[0].DirTag" Type="Str">{B9E310F1-839C-48B7-8CAE-33000780C26E}</Property>
				<Property Name="ShortcutInfo[0].FileTag" Type="Str">{A7962AA2-AEE2-4D58-8091-1F8EC7480E0F}</Property>
				<Property Name="ShortcutInfo[0].FileTagDir" Type="Str">{192D54F5-FFF1-4CFB-9CDE-C64B818D6BDA}</Property>
				<Property Name="ShortcutInfo[0].Name" Type="Str">acher</Property>
				<Property Name="ShortcutInfo[0].SubDir" Type="Str">Acher</Property>
				<Property Name="UpgradeCode" Type="Str">{1D887E17-22DD-4F58-80D1-81B384DB4F16}</Property>
				<Property Name="WindowMessage" Type="Str">Welcome to Acher!</Property>
				<Property Name="WindowTitle" Type="Str">Acher</Property>
			</Item>
		</Item>
	</Item>
</Project>
