# Write your MySQL query statement below
SELECT em.unique_id, e.name
FROM Employees e
    LEFT JOIN EmployeeUNI em
        ON e.id = em.id