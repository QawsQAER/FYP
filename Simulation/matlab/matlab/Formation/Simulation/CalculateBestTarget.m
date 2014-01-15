function [ Best_target ] = CalculateBestTarget(Exp_pos,target_list)
%   CalculateBestTarget will compute the distance from the quadcopter to
%   each of the target points, and determine which is the best(shortest)
%   choice for which.

%   Detailed explanation goes here
%   Best_target = [distance, quadcopter_number, target_number]
    dummy = [1];
%{
    distance = [value1, number of quadcopter, number of target]
             = [value1, number of quadcopter, number of target], order by
             ascdeing order of value1
%}
    distance = [];
    Best_target = [];
    
    for count = 1:size(Exp_pos,1)
       for count1 = 1:size(target_list,1)
        %fprintf('distance between %d, %d, x difference %f, y difference %f\n',count,count1,Exp_pos(count,2) - target_list(count1,2),Exp_pos(count,3) - target_list(count1,3));
        temp_distance = pdist([ Exp_pos(count,2),Exp_pos(count,3);target_list(count1,2),target_list(count1,3)]);
        distance = [distance; temp_distance,count,count1];
       end
    end
    
    
    distance = sortrows(distance);
    
    for count = 1:size(Exp_pos,1)
        temp = distance(1,:); %extract the record with the shortest distance
        Best_target = [Best_target;temp];%add the record into the best_target list
        
        quadcopter_number = temp(2);%record the quadcopter number for the following elimination
        target_number = temp(3);%record the target number for the following elimination
        count1 = 1;
        while(count1 <= size(distance,1))
            if(distance(count1,2) == quadcopter_number | distance(count1,3) == target_number)
                distance(count1,:) = []; %eliminate the record which has the same quadcopter number or target number
                count1 = 1;
            else
                count1 = count1 + 1;
            end
            
        end
        distance = sortrows(distance);
    end
    Best_target;
end

