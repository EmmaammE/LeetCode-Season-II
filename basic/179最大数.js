/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
  let res = nums.sort((a,b) => {
    if(''+a+b > ''+b+a) {
      return -1;
    } else {
      return 1;
    }
  }).join('');

  if(res[0]==='0') {
    res = '0';
  }

  return res;
};