// incomeTax.js
// 速算扣除数 ：3级，累计预扣预缴应纳税所得额不超过20000，20000~50000，超过50000。
var sskcs = new Array(0, 2000, 7000);
// 适用预扣率：3级，分别为20%、30%、40%
var ykl = new Array(0.2, 0.3, 0.4);
// jcfy:减除费用 ;ynssde:应纳税所得额;sysl:适用税率;
// sskcs:速算扣除数;yjsk:应缴税款;shsr:税后收入;
var jcfy,ynssde,sysl,sskcs,yjsk,shsr;

function $(id) {
  return document.getElementById(id);
}

function computer() {
  var sr = parseFloat($("lwbc").value);
  if (sr<800) {
    alert('收入少于800元，无需交税！');
  }else if (sr <= 4000) {
    jcfy = 800;
    ynssde = sr - jcfy;
    sysl = ykl[0];
    sskcs = 0;
    yjsk = ynssde * sysl;
    shsr = sr - yjsk;
  } else {
    jcfy = sr*0.20;
    // 设置适用税率、累计预扣预缴应纳税所得额与速算扣除数的关系
     ynssde = sr - jcfy;
    if (ynssde <= 20000) {
      sskcs = 0;
      sysl = ykl[0];
    } else if (ynssde > 20000 && ynssde <= 50000) {
      sysl = ykl[1];
      sskcs = 2000;
    } else {
      sskcs = 7000;
      sysl = ykl[2];
    }
    yjsk = ynssde * sysl-sskcs;
    shsr = sr - yjsk;
  }
  $("jcfy").innerHTML = jcfy.toFixed(2);
  $("ynssde").innerHTML = ynssde.toFixed(2);
  $("sysl").innerHTML = sysl * 100 + "%";
  $("sskcs").innerHTML = sskcs.toFixed(2);
  $("yjsk").innerHTML = yjsk.toFixed(2);
  $("shsr").innerHTML = shsr.toFixed(2);
}
