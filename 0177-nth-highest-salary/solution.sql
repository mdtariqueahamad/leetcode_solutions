CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N- 1;
Return(
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT N, 1
  );
END
