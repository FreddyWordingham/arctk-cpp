{
    std::cout << "I is : " << I << "\n";

    while (pos_[I - 1] > Bucket<T, N>::_max[I - 1])
    {
        Bucket<T, N>::_max[I - 1] += (Bucket<T, N>::_max[I - 1] - Bucket<T, N>::_min[I - 1]);
        Bucket<T, N>::_width[I - 1] *= 2.0;

        if constexpr (I > 1)
        {
            for (size_t i = 0; i < (Bucket<T, N>::_res[I - 1] / 2); ++i)
            {
                const size_t index = 2 * i;
                std::cout << bins_[index].size() << "\t:\t" << bins_[index + 1].size() << "\t:\t" << Bucket<T, N>::_res[I - 1]
                          << "\t:\t" << index << "\n";
                bins_[i] = math::add<T, I - 1>(bins_[index], bins_[index + 1]);
            }

            for (size_t i = (Bucket<T, N>::_res[I - 1] / 2); i < Bucket<T, N>::_res[I - 1]; ++i)
            {
                if constexpr (I > 2)
                {
                    utl::reset_MultiVec<T, I - 1>(Bucket<T, N>::_bins[i]);
                }
                else
                {
                    Bucket<T, N>::_bins[i] = {};
                }
            }
        }
        else
        {

            for (size_t i = 0; i < (Bucket<T, N>::_res[I - 1] / 2); ++i)
            {
                const size_t index = 2 * i;
                bins_[i]           = bins_[index] + bins_[index + 1];
            }

            for (size_t i = (Bucket<T, N>::_res[I - 1] / 2); i < Bucket<T, N>::_res[I - 1]; ++i)
            {
                bins_[i] = 0.0;
            }
        }
    }

    if constexpr (I > 1)
    {
        for (size_t i = 0; i < bins_.size(); ++i)
        {
            ascend<I - 1>(bins_[i], pos_);
        }
    }
}
