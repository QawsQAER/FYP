function [ waypoint ] = Path_PlanningV1( now_pos,now_vel,target_list,delay )
    
    Exp_pos = CalculateExpectPosition(now_pos,now_vel,delay);
    Best_target = CalculateBestTarget(Exp_pos,target_list);
    
    waypoint = Best_target;
end

