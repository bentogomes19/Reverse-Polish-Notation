# Reverse Polish Notation (RPN)

Also called postfix notation for expressions, this is a derivation of the original Polish Notation proposal created by mathematician Jan Łukasiewicz and first used in computing by scientist Charles Hamblin, presenting a series of facilities in relation to the traditional in-fix notation.

<hr>

This program it's a homework from my college to try to convert a arithmetic expressions from reverse polish notation

This program don't calculate the expression.

- Example:
    > Expression: (A+B)*C
    > RPN : A B C * +

    > Expression: A + B / (C*D)
    > RPN: A B C D * / +

***OBS: Can exists more than a solution, for example,   a+b+c can be writed like abc++ or ab + c +*** 

Operation


\[
\frac{a \cdot b - c \cdot d}{e \cdot f}
\]

 > RPN -> a b * c d * - e f * /