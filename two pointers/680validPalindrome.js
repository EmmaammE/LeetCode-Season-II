/**
 * 
 */

/**
* @param {string} s
* @return {boolean}
*/
var validPalindrome = function (s) {
    function isPalindromeRange(s, i, j) {
        for (let k = i; k <= i + (j - i) / 2; k++) {
            if (s.charAt(k) !== s.charAt(j - k + i)) return false;
        }
        return true;
    }

    for (let i = 0; i < Math.floor(s.length / 2); i++) {
        if (s.charAt(i) !== s.charAt(s.length - 1 - i)) {
            let j = s.length - 1 - i;
            return (isPalindromeRange(s, i + 1, j) ||
                isPalindromeRange(s, i, j - 1));
        }
    }
    return true;
};


/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function (s) {
    let left = 0, right = s.length - 1, deleted = 0;

    while (left <= right && deleted < 2) {
        if (s[left] === s[right]) {
            left++;
            right--;
        } else {
            // 如果删除left指向的位置
            if (s[left + 1] === s[right] && s[left + 2] === s[right - 1]) {
                deleted++;
                left += 3;
                right -= 2;
            } else if (s[left] === s[right - 1]) {
                deleted++;
                left++;
                right -= 2;
            } else {
                deleted += 2;
                left++;
                right--;
            }
        }
    }

    return deleted < 2;
};
