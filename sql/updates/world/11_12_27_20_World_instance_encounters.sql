-- DB/ENCOUNTERS: Fix all errors on console about instance encounters
-- Deleting Zul'jin instance enconters Zul'Aman was implemented on 4.1 patch
DELETE FROM `instance_encounters` WHERE `entry`='783';