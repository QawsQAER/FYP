function drawpoints(number)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here    
if(number == 6)
        now_pos = [1.0000   20.3810    5.2815;
                   2.0000   40.9991   30.5479;
                   3.0000   35.9179   38.9401;
                   4.0000   48.4325   21.1726;
                   5.0000   26.5667    4.5412;
                   6.0000   16.2573   13.3236];

    
    target_list = [1 15 25;
                                   2 20 15;
                                   3 30 15;
                                   4 35 25;
                                   5 30 35;
                                   6 20 35;];
end
%--------------------------------------------------%
if(number == 3)
         now_pos = [1.0000   25.7946   22.3345;
                2.0000   44.7713   24.3467;
                3.0000   11.0105   40.4857;];
    target_list = [1 16.67,15;2 33.22,15;3 25,40]; 
    
end
%--------------------------------------------------%
            plot(now_pos(1:end,2),now_pos(1:end,3),'>k'); hold on;
           plot(target_list(1:end,2),target_list(1:end,3),'.b'); hold on;
           axis([0,50,0,50]);
           hleg1 = legend('quadcopter','target');
end

