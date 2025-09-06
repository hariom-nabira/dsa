# Write your MySQL query statement below
SELECT sxs.student_id, sxs.student_name, sxs.subject_name, COUNT(e.student_id) AS attended_exams
FROM (SELECT * FROM Students, Subjects) sxs
    LEFT JOIN Examinations e
        ON sxs.student_id = e.student_id
        AND sxs.subject_name = e.subject_name
GROUP BY sxs.student_id, sxs.subject_name
ORDER BY sxs.student_id, sxs.subject_name;