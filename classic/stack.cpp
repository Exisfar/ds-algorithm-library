#include "data_structure.h"

/** 最长有效括号
 *
 */
int Stack::longestValidParentheses(string s) {
  stack<int> st;
  int n = s.size();
  int res = 0;
  int start = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      // 此时前面的子串不可能再与后面的子串匹配
      // 后续的有效括号从start开始
      if (st.empty()) {
        start = i;
      } else {
        st.pop();
        // 考虑已匹配的括号前面是否还有'('未匹配
        if (st.empty())
          // 栈空，说明start之后的括号均已配对
          res = max(i - start, res);
        else
          // 栈非空，说明栈顶元素是未配对的'('，当前有效括号只能从最近的'('算
          res = max(i - st.top(), res);
      }
    }
  }
  return res;
}