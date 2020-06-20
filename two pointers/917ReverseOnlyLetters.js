/**
 * @param {string} S
 * @return {string}
 */
var reverseOnlyLetters = function (S) {
    let s = S.split('');

    const isAlpha = ch => {
        return ch.match(/^[a-z]+$/i) !== null;
    }

    let left = 0, right = s.length-1;
    while(left < right) {
        while(left < right && !isAlpha(s[left])) {
            left++;
        }

        while(left < right && !isAlpha(s[right])) {
            right--;
        }

        let temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
    
    return s.join('');
};