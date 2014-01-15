function Simulation( number ,framenumber,moving)

%
%   This function simulate the formation of quadcopters.
    [now_pos,now_vel,target_list,waypoint] = Initilized(number);
    now_pos
    prev_vel = zeros(number,2); % stored the previous velocity for PID control. 
    integral = zeros(number,2);

    delay = 0;
    second = 1;
    time = 0.25;

    no_curve = 1;
    Best_target = [];
    [quadnum_targetX_targetY Best_target] = Path_Planning(now_pos,now_vel,target_list,delay);
    
    %ultimate target of each quadcopter = [quadcopter num, target X, targetY]
    record = quadnum_targetX_targetY;
    Best_target
    
    while(second < framenumber)
           if(no_curve == 1)
           clf;
           end 
           
           quadnum_targetX_targetY = record;
            
          
           %recalculate the distance according to the new position, and sort them
           %in ascending order in terms of distance
           for count = 1:size(Best_target,1)
                quad_num = Best_target(count,2);
                target_num = Best_target(count,3);
                
                pos_quad = now_pos(quad_num,2:3);
                pos_target = target_list(target_num,2:3);
                
                %refresh the new distance
                Best_target(count,1) = pdist([pos_quad;pos_target]);
               
           end
           sortrows(Best_target);
           %-----------------------------------------------------------------------%
           
           %draw the position of the current quadcopter and ultimate target
           plot(now_pos(1:end,2),now_pos(1:end,3),'>k'); hold on;
           plot(target_list(1:end,2),target_list(1:end,3),'.b'); hold on;
           hleg1 = legend('quadcopter','target');
           
           %Check for any crossing, and out the crossed path with
           %[quadcopter num, new target X ,new target Y]
           if(framenumber < 3)
           new_waypoint = quadnum_targetX_targetY;
           else
           new_waypoint = Alterwaypoint(now_pos,Best_target,target_list);
           end
           
           
           
           %Update the old list with [quadcopter num, new target X, new target Y]
           for count = 1:size(new_waypoint,1)
                for count1 = 1:size(quadnum_targetX_targetY,1)
                    if(quadnum_targetX_targetY(count1,1) == new_waypoint(count,1))
                        quadnum_targetX_targetY(count1,2) = new_waypoint(count,2);
                        quadnum_targetX_targetY(count1,3) = new_waypoint(count,3);
                    end
                end
           end
           
           Best_target;
           quadnum_targetX_targetY;
           
           for count = 1:number
           x1 = [now_pos(Best_target(count,2),2),target_list(Best_target(count,3),2)];
           y1 = [now_pos(Best_target(count,2),3),target_list(Best_target(count,3),3)];
           plot(x1,y1,'g'); hold on;
           end
           
           
           %draw the line between the quadcopter and the current target
           for count = 1:number
           x1 = [now_pos(quadnum_targetX_targetY(count,1),2),quadnum_targetX_targetY(count,2)];
           y1 = [now_pos(quadnum_targetX_targetY(count,1),3),quadnum_targetX_targetY(count,3)];
           if(framenumber > 1)
            plot(x1,y1,'r');
           end
           end
            
           
           axis([0,50,0,50]);
           M(second) = getframe;
           [now_vel] = SimulateQuadcopterSwarm(now_pos,now_vel,quadnum_targetX_targetY,prev_vel,integral,number);
           now_vel = sortrows(now_vel);
           now_pos(1:end,2:3) = now_pos(1:end,2:3) + now_vel(1:end,2:3).* time;
           
           %change the distance record for the Best_target
           
           for count = 1:size(Best_target,1)
                Best_target(count,1) = pdist2(now_pos(Best_target(count,2),2:3),target_list(Best_target(count,3),2:3));
           end
           sortrows(Best_target);
           
           %move the target position
           if(moving == 1)
           for count = 1:size(target_list,1)
                %if(mod(count,2) == 0)
                target_list(count,2) = target_list(count,2) + 0.05;
                target_list(count,3) = target_list(count,3) + 0.05;
                
                %{
                else
                target_list(count,2) = target_list(count,2) + 0.05;
                target_list(count,3) = target_list(count,3) - 0.05;    
                %}
                %end
              
           end
           end
           second = second + 1;
    end
    
    if(framenumber > 1)
    movie(M,1,30);
    %movie2avi(M,'hehe.avi');
    movie2gif(M,'real.gif','DelayTime',0.1);
    end
end

