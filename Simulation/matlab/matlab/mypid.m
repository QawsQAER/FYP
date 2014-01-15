function result = mypid(deviation,deviation1,P,I,D,color,draw)

length = 20;
factor = 5;
t = linspace(0,length,length * factor);
mag_noise = 0;%(deviation + deviation1) / (2  * length * factor) ;
noise_mean = 0;
noise_dev = 1;
period = 0;
setpoint = ones(length * factor);
threshold = 1;
count_threshold = 5;
count = 3;

count1 = 0;
count2 = 0;

%P = 500;
%I = 200;
%D = 15;
est = [1:length * factor];
err = [1:length * factor];

est1 = [1:length * factor];
err1 = [1:length * factor];

set = 0;
sum = 0;
sum1 = 0;

kilo = 1000;

%deviation = 125;

est(1) = set;
err(1) = set - est(1);
est1(1) = set;
err1(1) = set - est1(1);

est(2) = set;
err(2) = set - est(2);
est1(1) = set;
err1(1) = set - est1(1);

est(3) = deviation;
err(3) = set - est(3);
est1(3) = deviation1;
err1(3) = set - est(3);


est(4) = deviation;
err(4) = set - est(4);
est1(4) = deviation1;
err1(4) = set - est(4);

p_term = 0;
i_term = 0;
d_term = 0;


while (count < length * factor) 

        err(count) = set - est(count);
        if(abs(err(count)) < threshold & count1 <= count_threshold)
            count1 = count1 + 1;
            if(count1 > count_threshold)
               fprintf(1,'Threshold time1: %f\n',count / factor );
               result = count / factor;
               if(draw == 0)
                  return;
              end
            end
        elseif(abs(err(count)) > threshold)
            count1 = 0;
        end
        
        sum = sum + err(count);
        p_term = P * err(count) / kilo;
        i_term = I * sum / kilo;
        d_term = D * ( err(count) - err(count - 1) ) / kilo;
        
        
        est(count + 1) =  p_term + i_term + d_term + est(count) + mag_noise * normrnd(noise_mean,noise_dev);
        

        err1(count) = set - est1(count);
        if(abs(err1(count)) < threshold & count2 <= count_threshold)
            count2 = count2 + 1;
            if(count2 > count_threshold)
             fprintf(1,'Threshold time2: %f\n',count /  factor );
             
            end
        elseif(abs(err1(count)) > threshold)
           count2 = 0;
        end
        sum1 = sum1 + err1(count);
        p_term = P * err1(count) / kilo;
        i_term = I * sum1 / kilo;
        d_term = D * ( err1(count) - err1(count - 1) ) / kilo;
       
        est1(count + 1) =  p_term + i_term + d_term + est1(count) + mag_noise * normrnd(noise_mean,noise_dev);
        
        count = count + 1;    
        if(period ~= 0)
        if (rem(count,period) == 0)
         est(count) = est(count) + deviation;
         est1(count) = est1(count) + deviation1;
        end
        end
        
        
end;

plot(t,est,color,'LineWidth',1);
hold on
if(deviation1 ~= 0)
plot(t,est1,'k','LineWidth',1);
hold on
end
plot(t,setpoint,'r');
