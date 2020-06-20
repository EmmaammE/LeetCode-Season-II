/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
    s = s.replace(/[^\w+]/g, '').toLowerCase()
    let low = 0;
    let high = s.length - 1;

    while (low < high) {
        if (s[low] !== s[high]) {
            return false
        }
        low++
        high--
    }
    return true
};