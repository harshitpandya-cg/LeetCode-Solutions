select Max(salary) as secondHighestSalary from employee 
where salary < (select Max(salary) from employee);