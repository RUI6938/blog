// factorial.js
// 1.定义计算某个整数阶乘的函数
function $(id) {return document.getElementById(id)}
function factorial(n) {
  var result = 1,i = 1;
  while (i <= n) {
    result = result * i;
    i++;
  }
  return result;
}
// 2.定义计算某一区间[m,n]内整数的阶乘累加和
function factorialSum(m, n) {
  for (var i = m, sum = 0; i <= n; i++) {
    sum = sum + factorial(i);
  }
  return sum
}
//3.获取输入的区间起始整数和终止整数，并计算累加和，回填文本框中
function displaySum() {
  var m = parseInt($("m").value);
  var n = parseInt($("n").value);
  // 处理m、n的大小关系,m<=n
  var min = Math.min(m, n);
  var max = Math.max(m, n);
  // 互换位置   
  $("sum").value = factorialSum(min, max);
  $("m").value = min;
  $("n").value = max;
}
