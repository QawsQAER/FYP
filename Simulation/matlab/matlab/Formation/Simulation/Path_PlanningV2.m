function [temp_target Best_target] = Path_PlanningV2(now_pos,now_vel,target_list,delay,second,Best_target);
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    Exp_pos = CalculateExpectPosition(now_pos,now_vel,delay);
    Best_target = CalculateBestTarget(Exp_pos,target_list);
    
    
    quadnum_targetX_targetY  = [];
    %Re-orgnized the data into format [quadnum, target X coordiante , target Y coordinate]
    for count = 1:size(Best_target,1)
        quadnum_targetX_targetY = [quadnum_targetX_targetY;Best_target(count,2),target_list(Best_target(count,3),2),target_list(Best_target(count,3),3)];
    end
    quadnum_targetX_targetY;
    original_waypoint = Best_target;
    
    %{
    new_waypoint = Alterwaypoint(Exp_pos,original_waypoint,target_list);
    %Search through the quadnum_targetX_targetY for any update by
    %Alterwaypoint
    for count = 1:size(new_waypoint,1)
        for count1 = 1:size(quadnum_targetX_targetY,1)
            if(quadnum_targetX_targetY(count1,1) == new_waypoint(count,1))
                quadnum_targetX_targetY(count1,2) = new_waypoint(count,2);
                quadnum_targetX_targetY(count1,3) = new_waypoint(count,3);
            end
        end
    end
    %}
    
    
    temp_target = quadnum_targetX_targetY;
    temp_target;
end

