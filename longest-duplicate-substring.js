function longestDuplicateSubstring(str) {
  // Implement your code here
  // Note: Function must return some value
  for (let len = str.length - 1; len >= 1; len -= 1) {
    let isFound = {};
    let target = str.substr(0, len);
    isFound[target] = true;
    for (let i = len; i < str.length; i += 1) {
      target = target.substr(1) + str[i];
      if (isFound[target]) {
        return target;
      }
    }
  }
  return "Not Found";
}

console.log(longestDuplicateSubstring("abcab"));
console.log(longestDuplicateSubstring("zzz"));
console.log(longestDuplicateSubstring("testtesttest"));
console.log(longestDuplicateSubstring("abc"));
