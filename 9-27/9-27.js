/*计算任意区间内连续自然数的累加和sum.js*/
//以Id号获取HTML页面元素
function $(id){return document.getElementById(id);}
//计算区间自然数累加和
function sum(n1,n2){
   for (var i=n1,sum1=0;i<=n2 ;i++ )
   {
	   sum1=sum1+i;
   }
   return sum1;
}
//显示累加和
function show(){
   var n11=parseFloat($("start_num").value);
   var n22=parseFloat($("end_num").value);
   if (n11>0 && n22>0)   //输入数据必须不为0
   { 
    if ( n11>=n22)
	{alert("起始数必须小天终止数，请重输！");
	  $("start_num").value="";   //清空文本域
	  $("end_num").value="";    //清空文本域
	}
	else{  //回填累加和文本框
    $("sum").value=sum(n11,n22);
  }
 }else
	{alert("请输入数据！");
      $("start_num").focus();  //文本域获得焦点
	}
}