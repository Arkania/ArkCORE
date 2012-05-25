-- Dismount and disabled Mounts
UPDATE instance_template SET allowMount = 1 WHERE map IN (
757,  -- Baradinhold
643,  -- Throne of Tides
645,  -- Blackrock Caverns
670,  -- Grim Batol
644,  -- Halls of Origination
657,  -- Vortex Pinnacle
669,  -- Blackwingdescent
671,  -- Bastion of Twillight
725); -- The Stonecore

-- Deleted Fireland Instance Query
DELETE FROM instance_template WHERE map = 720;