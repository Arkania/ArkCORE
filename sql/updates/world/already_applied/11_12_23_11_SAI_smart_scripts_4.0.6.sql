-- DB/SAI: Deleting some SAI for 4.1 or 4.2 clients (read note)
-- Please don't use this fix on 4.2 or 4.3 clientes cos I delete this SAI cos this creatures don't existon 4.0.6
DELETE FROM `smart_scripts` WHERE `entryorguid` IN ('52839','53094','53096','53120','53127','53134','53141','53187','53188','53223','53244','53585','53621','53622','53732','53901','54073','54144');