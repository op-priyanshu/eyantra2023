transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/store_extend.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/reset_ff.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/reg_file.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/mux4.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/mux2.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/main_decoder.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/load_extend.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/imm_extend.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/datapath.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/controller.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/alu_decoder.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/alu.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/components/adder.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/t2b_riscv_cpu_tutorial.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/data_mem.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/riscv_cpu.v}
vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/instr_mem.v}

vlog -vlog01compat -work work +incdir+C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/.testbench {C:/Users/priyanshu/Desktop/eyantra2023/task2/t2b_riscv_cpu_tutorial/.testbench/tb.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb

add wave *
view structure
view signals
run 10 us
