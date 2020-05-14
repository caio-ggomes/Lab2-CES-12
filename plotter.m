ydata = time_ins_alu;
x0 = [0.001, 0];
x = lsqcurvefit(fun,x0,qtde,ydata);

quantities = linspace(qtde(1),qtde(end));
plot(qtde,ydata,'ko',quantities,fun(x,quantities),'b-');
legend('Data', 'Fitted logarithm');
title('Tempo de inserção ALU');
ylabel('Tempo(s)');
xlabel('Quantidade de nós');