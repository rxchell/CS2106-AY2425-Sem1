Last login: Sun Sep 15 08:59:45 on ttys000
rachel@Rachels-MacBook-Air ~ % ssh rachelt@xlog.comp.nus.edu.sg 

rachelt@xlog.comp.nus.edu.sg's password: 
======================( Welcome to SoC Compute Cluster! )=====================
Documentation is at https://dochub.comp.nus.edu.sg/cf/guides/compute-cluster/.
______________________________________________________________________________

** Current Cluster allocation: CPU=5.5%, Memory=6.6%, GPU=23.7%
** [AH]100-specific: A100-40=46.7%, A100-80=70.0%, H100-47=3.3%, H100-96=55.0%

Last login: Sat Sep 14 17:07:02 2024 from 192.168.152.188
rachelt@xlogin1:~$ cd L02/part1/batch
rachelt@xlogin1:~/L02/part1/batch$ ./process_jobs.sh run
Summary report generated at summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ cd jobs
rachelt@xlogin1:~/L02/part1/batch/jobs$ ls
A0183741Y  A0281754H  A0285757B  log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs$ ls log.txt
log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs$ vim log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs$ cd jobs
-bash: cd: jobs: No such file or directory
rachelt@xlogin1:~/L02/part1/batch/jobs$ ls
A0183741Y  A0281754H  A0285757B  log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs$ cd A0183741Y
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ ls
log.txt  run  s1.in  s1.in.out	sum.c  utils.c	utils.h
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ vim log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ cd ~../..
-bash: cd: ~../..: No such file or directory
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ cd ../..
rachelt@xlogin1:~/L02/part1/batch$ ls
jobs  process_jobs.sh  summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim process_jobs.sh







rachelt@xlogin1:~/L02/part1/batch$ ./process_jobs.sh run
Summary Report
Summary report generated at summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim process_jobs.sh
rachelt@xlogin1:~/L02/part1/batch$ ./process_jobs.sh run
Summary report generated at summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ cd jobs
rachelt@xlogin1:~/L02/part1/batch/jobs$ ls
A0183741Y  A0281754H  A0285757B  log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs$ cd A0183741Y
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ ls
log.txt  run  s1.in  s1.in.out	sum.c  utils.c	utils.h
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ vim log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ cd ../..
rachelt@xlogin1:~/L02/part1/batch$ ls
jobs  process_jobs.sh  summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim process_jobs.sh
rachelt@xlogin1:~/L02/part1/batch$ vim process_jobs.sh
rachelt@xlogin1:~/L02/part1/batch$ ./process_jobs.sh run
Summary report generated at summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim summary.report.txt
rachelt@xlogin1:~/L02/part1/batch$ ls
1  jobs  process_jobs.sh  summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ rm 1
ls
rachelt@xlogin1:~/L02/part1/batch$ ls
jobs  process_jobs.sh  summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ cd jobs
rachelt@xlogin1:~/L02/part1/batch/jobs$ ls
A0183741Y  A0281754H  A0285757B  log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs$ cd A0183741Y
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ ls
log.txt  run  s1.in  s1.in.out	sum.c  utils.c	utils.h
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ vim log.txt
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ ../..
-bash: ../..: Is a directory
rachelt@xlogin1:~/L02/part1/batch/jobs/A0183741Y$ cd ../..
rachelt@xlogin1:~/L02/part1/batch$ ls
jobs  process_jobs.sh  summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim summary_report.txt
rachelt@xlogin1:~/L02/part1/batch$ vim process_jobs.sh

            continue
        fi

        total_jobs=$((total_jobs + 1))

        echo "Compiling ${source_files[*]}" >> "$student_dir/log.txt"
        gcc "${source_files[@]}" -o "$student_dir/$program_name" 2>> "$student_dir/log.txt"

        if [ $? -ne 0 ]; then
            echo "Compilation failure for jobs/$student_name" >> "$student_dir/log.txt"
            failed_compilations=$((failed_compilations + 1))
            continue
        else
            echo "Compilation successful for jobs/$student_name" >> "$student_dir/log.txt"
            successful_compilations=$((successful_compilations + 1))
        fi

        # Process each input file
        input_files=("$student_dir"/*.in)
        if [ ${#input_files[@]} -eq 0 ]; then
            echo "No input files found for $student_name" >> "$student_dir/log.txt"
        fi

        for input_file in "${input_files[@]}"; do
            output_file="${input_file}.out"
            start_time=$(date +%s.%N)

            # Run the compiled program
            ./"$student_dir/$program_name" < "$input_file" > "$output_file" 2>> "$student_dir/log.txt"

            end_time=$(date +%s.%N)
            elapsed_time=$(echo "$end_time - $start_time" | bc)

            echo "Execution time for $input_file: $elapsed_time seconds" >> "$student_dir/log.txt"

            # Check for runtime errors
            if [ $? -ne 0 ]; then
                echo "Runtime error encountered while processing $input_file" >> "$student_dir/log.txt"
            fi

            total_runtime=$(echo "$total_runtime + $elapsed_time" | bc)
        done


    fi
done

# Generate the summary report
echo "Summary Report" >> "$summary_report"
echo "Total jobs processed: $total_jobs" >> "$summary_report"
echo "Successful compilations: $successful_compilations" >> "$summary_report"
echo "Failed compilations: $failed_compilations" >> "$summary_report"
echo "Total runtime of all jobs: $total_runtime seconds" >> "$summary_report"

echo "Summary report generated at $summary_report"
