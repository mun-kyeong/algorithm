
select f.FLAVOR
from FIRST_HALF f
join
   (select FLAVOR, sum(TOTAL_ORDER) as TOTAL
    from JULY
    group by FLAVOR) j
        on f.FLAVOR = j.FLAVOR
order by f.TOTAL_ORDER + j.TOTAL desc
limit 3