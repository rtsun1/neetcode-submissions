class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t not in ["+", "-", "*", "/"]:
                stack.append(int(t))
                continue
            op2 = stack.pop()
            op1 = stack.pop()
            match t:
                case "+":
                    result = op1 + op2
                case "-":
                    result = op1 - op2
                case "*":
                    result = op1 * op2
                case "/":
                    # print(op1, op2)
                    result = int(op1 / op2)
            stack.append(result)
        
        # print(len(stack))
        return stack.pop()
