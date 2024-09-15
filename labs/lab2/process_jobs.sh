#!/bin/bash

# Check if exactly one argument is supplied
if [ "$#" -ne 1 ]; then
    # Echo this message if not exactly one argument is supplied
    echo "Usage: ./process_jobs.sh <filename>"
    exit 1
fi

program_name=$1
jobs_dir="jobs"
summary_report="summary_report.txt"

# Initialize counters for summary report
total_jobs=0
successful_compilations=0
failed_compilations=0
total_runtime=0

# Clear previous summary report if it exists
> "$summary_report"

# Iterate over each student directory in the jobs/ directory
for student_dir in "$jobs_dir"/*; do
    # If student directory exists
    if [ -d "$student_dir" ]; then
        # Clear existing log file
        > "$student_dir/log.txt"

        # Initialise number of errors
        total_errors=0

        student_name=$(basename "$student_dir")
        echo "Processing student job in jobs/$student_name" >> "$student_dir/log.txt"

        # Compile the C source files
        source_files=("$student_dir"/*.c)
        if [ ${#source_files[@]} -eq 0 ]; then
            echo "No C source files found for $student_name" >> "$student_dir/log.txt"
            continue
        fi

        total_jobs=$((total_jobs + 1))

        echo "Compiling ${source_files[*]}" >> "$student_dir/log.txt"
        gcc "${source_files[@]}" -o "$student_dir/$program_name" 2>> "$student_dir/log.txt"

        if [ $? -ne 0 ]; then
            total_errors=$((total_errors + 1))
            echo "$total_errors error generated." >> "$student_dir/log.txt"
            echo "Compilation failed for jobs/$student_name" >> "$student_dir/log.txt"
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
